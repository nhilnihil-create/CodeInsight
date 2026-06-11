#include<iostream>
#include<vector>
#include<string>

int main(){
    int map[3][3];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            std::cin >> map[i][j];
        }
    }

    for(int a1 = 0; a1 <= 100; a1++){
        bool ok = true;
        int b[3];
        int a[3];
        a[0] = a1;
        for(int i = 0; i < 3; i++){
            b[i] = map[0][i] - a[0];
        }
        a[1] = map[1][0] - b[0];
        a[2] = map[2][0] - b[0];

        // 全て満たしているかチェック
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(a[i] + b[j] != map[i][j]){
                    ok = false;
                    break;
                }
            }

            if(!ok) break;
        }

        if(ok){
            std::cout << "Yes" << std::endl;
            return 0;
        }
    }

    std::cout << "No" << std::endl;

    return 0;
}
