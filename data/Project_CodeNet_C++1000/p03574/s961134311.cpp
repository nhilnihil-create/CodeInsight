#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

 
int main() {
    int H, W;
    cin >> H >> W;
    char s[60][60];
    char ans[60][60];
    int dx[8] = {1,1,0,-1,-1,-1,0,1};
    int dy[8] = {0,1,1,1,0,-1,-1,-1};
    for(int i = 1; i <= H; i++)
        for(int j = 1; j <= W; j++)
            cin >> s[i][j];

    for(int i = 0; i < 60; i++)
        for(int j = 0; j < 60; j++)
            ans[i][j] = '#';
    
    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j++){
            if(s[i][j] == '.'){
                char cnt = 0;
                for(int k = 0; k < 8; k++){
                    int i2 = i + dx[k];
                    int j2 = j + dy[k];
                    if(s[i2][j2] == '#'){
                        cnt++;
                    }
                }
                ans[i][j] = cnt + '0';
            }
        }
    }


    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j++){
            cout << ans[i][j];
        }
        cout << endl;
    }

    return 0;
}