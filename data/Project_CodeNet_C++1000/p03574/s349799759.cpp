#include<bits/stdc++.h>
using namespace std;

int h, w;
int dx[] = {0, 0, -1, 1, -1, -1, 1, 1};
int dy[] = {-1, 1, 0, 0, -1, 1, -1, 1};

int main(void){
    cin >> h >> w;
    vector<string> f(h);
    for(int i = 0; i < h; i++) cin >> f[i];
    vector<vector<int>> t(h, vector<int>(w, -1));
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(f[i][j] == '.'){
                t[i][j] = 0;
                for(int k = 0; k < 8; k++){
                    int nx = i+dx[k];
                    int ny = j+dy[k];
                    if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                    if(f[nx][ny] == '#') t[i][j]++;
                }
            }
        }
    }
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(t[i][j] == -1) cout << '#';
            else cout << t[i][j];
        }
        cout << endl;
    }
    return 0;
}
