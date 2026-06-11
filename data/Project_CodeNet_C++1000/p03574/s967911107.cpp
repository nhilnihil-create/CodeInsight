#include <iostream>
#include <vector>

int check_mine(std::vector<std::vector<char>> grid, int p, int q){
    int mine = 0;
    for (int i = p; i < p + 3; ++i){
        for (int j = q; j < q + 3; ++j){
            if (grid[i][j] == '#'){
                ++mine;
            }
        }
    }
    return mine;
}

int main(void){
    int H, W;
    std::cin >> H >> W;
    std::vector<std::vector<char>> grid(H + 2, std::vector<char>(W + 2, '*'));
    for (int i = 0; i < H; ++i){
        std::string S;
        std::cin >> S;
        for (int j = 0; j < W; ++j){
            grid[i + 1][j + 1] = S[j];
        }
    }

    for (int i = 0; i < H; ++i){
        for (int j = 0; j < W; ++j){
            if (grid[i + 1][j + 1] == '.'){
                grid[i + 1][j + 1] = '0'+ check_mine(grid, i, j);
            }
        }
    }

    for (int i = 0; i < H; ++i){
        for (int j = 0; j < W; ++j){
            std::cout << grid[i + 1][j + 1];
        }
        std::cout << std::endl;
    }

    return 0;
}
