#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

int main() {
    int h, w;
    std::cin >> h >> w;
    char s[100][100];
    int grid[100][100];
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++) {
            grid[i][j] = 0;
     
            std::cin >> s[i][j];
        
        }
       
    }
  

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (s[i][j] == '#')
            {
                for (int dx = -1; dx <= 1; dx++) {
                    for (int dy = -1; dy <= 1; dy++) {
                        int x = dx + j;
                        int y = dy + i;
                        if(x >= 0 && x < w && y >= 0 && y < h) {
                            grid[y][x]++;
                        }
                    }
                }
            }
        } 
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if(s[i][j] != '#') {
                std::cout << grid[i][j];
            } else {
                std::cout << '#';
            }
        }

        std::cout << "\n";
    }
}