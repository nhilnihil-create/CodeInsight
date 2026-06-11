#include <iostream>

enum HinaArareColor {
    PINK,
    WHITE,
    GREEN,
    YELLOW,
    NUM_OF_HINA_ARARE_COLORS
};
    
 
int main() {
    int numOfArares = 0;
    std::cin >> numOfArares;
    char* hinaArareBag = new char[numOfArares];
    
    bool hinaArareColors[NUM_OF_HINA_ARARE_COLORS] = {false, false, false, false};
    int numOfColors = 0;
    for (int i = 0; i < numOfArares; i++) {
        std::cin >> hinaArareBag[i];
        switch (hinaArareBag[i]) {
            case 'P':
                hinaArareColors[PINK] = true;
                break;
            case 'W':
                hinaArareColors[WHITE] = true;
                break;
            case 'G':
                hinaArareColors[GREEN] = true;
                break;
            case 'Y':
                hinaArareColors[YELLOW] = true;
                break;
        }
        numOfColors = 0;
        for (int indexOfColor = 0; indexOfColor < NUM_OF_HINA_ARARE_COLORS; indexOfColor++) {
            if (hinaArareColors[indexOfColor]) {
                numOfColors++;
            }
        }
        if (numOfColors == NUM_OF_HINA_ARARE_COLORS) {
            break;
        }
    }
    if (numOfColors == 3) {
        std::cout << "Three" << std::endl;
    } else if (numOfColors == 4) {
        std::cout << "Four" << std::endl;
    }
    
    delete[] hinaArareBag;
}