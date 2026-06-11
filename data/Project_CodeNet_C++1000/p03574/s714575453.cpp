#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int h,w;
    cin >> h >> w;
    vector<string> s(h);
    for(int i = 0; i < h; i++) cin >> s[i];

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            int tmp = 0;
            if(s[i][j] == '.'){
                for(int x = -1; x < 2; x++){
                    for(int y = -1; y < 2; y++){
                        int nx = x + i, ny = y + j;
                        if(nx >= 0 && nx < h && ny >= 0 && ny < w){
                            if(s[nx][ny] == '#') tmp++;
                        }
                    }
                }
                s[i][j] = char(tmp + '0');
            }
        }
    }
    for(string a : s) cout << a << endl;
}