#include<iostream>
#include<vector>
#include<string>

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int main(){
    int h, w;
    std::cin >> h >> w;
    std::vector<std::vector<char>> stage(h, std::vector<char>(w));
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++) std::cin >> stage[i][j];
    }

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(stage[i][j] != '#') continue;
            int k;
            for(k = 0; k < 4; k++){
                if(i + dx[k] >= 0 && i + dx[k] < h){
                    if(j + dy[k] >= 0 && j + dy[k] < w){
                        if(stage[i + dx[k]][j + dy[k]] == '#') break;
                    }
                }
            }
            if(k == 4){
                std::cout << "No" << std::endl;
                return 0;
            }
        }
    }
    std::cout << "Yes" << std::endl;
    return 0;
}
