#pragma once

#include <string>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Rect.hpp>

class GameObject {
    public:
        GameObject() = default;
        GameObject(std::string const & filename, sf::Vector2f const & position);
        virtual ~GameObject() = default;

        virtual void load(std::string const & filename);
        virtual void draw(sf::RenderWindow& window);
        virtual void update(float const & elapsedTime){};

        virtual void setPosition(sf::Vector2f const & position);
        virtual sf::Vector2f getPosition() const;
        virtual uint getWidth()  const;
        virtual uint getHeight() const;
        virtual sf::Rect<float> getBoundingRectangle() const;

        virtual bool isLoaded() const;

    protected:
        sf::Sprite& getSprite();

    private:
        bool isTextureLoaded{false};
        sf::Texture texture{};
        sf::Sprite  sprite{};
        std::string fileName{""};
};
