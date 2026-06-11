#include<iostream>
#include<string>
#include<vector>
#include <algorithm>

int dx [4] = {1, 0, -1, 0};
int dy [4] = {0, 1, 0, -1};

int main() {
    int h, w;
    std::cin >> h >> w;

    std::vector<std::vector<char>> s(h, std::vector<char>(w));
    for(int i = 0;i < h; i++) {
        for(int j = 0; j < w; j++) {
            std::cin >> s[i][j];
        }
    }

    bool f = true;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {

            if(s[i][j] == '#') {
                int cnt = 0;
                for(int k = 0; k < 4; k++) {
                
                        int nx = i + dy[k];
                        int ny = j + dx[k];

                        if(nx >= 0 && nx < h && ny >= 0 && ny < w) {
                            if(s[nx][ny] != '#') {
                                cnt ++;
                            }
                        }
                }     

                if(cnt >= 4) {
                    f = false;
                }   
            }



        }
    }


    std::string ans = f?"Yes":"No";

    std::cout << ans << std::endl;
}