#include <iostream>
using namespace std;
int main(){
    int h,w;
    char s[55][55];
    cin >> h >> w;
    for(int i = 0;i<h;i++){
        for(int j = 0;j<w;j++){
            cin >> s[i][j];
        }
    }
    const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
    const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
    for(int i = 0;i<h;i++){
        for(int j = 0;j<w;j++){
            if(s[i][j] == '#'){
                continue;
            }
            int count = 0;
            for(int k = 0;k<8;k++){
                int x = j + dx[k];
                int y = i + dy[k];
                if(x<0 || w<=x){
                    continue;
                }
                if(y<0 || h<=y){
                    continue;
                }
                if(s[y][x] == '#'){
                    count++;
                }
            }
            s[i][j] = count + '0';
        }
    }
    for(int i = 0;i<h;i++){
        for(int j = 0;j<w;j++){
            cout << s[i][j];
        }
        cout << endl;
    }
    return 0;
}