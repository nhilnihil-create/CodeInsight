#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

 
int main() {
    int H, W;
    cin >> H >> W;
    char s[60][60] = {0};
    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j++){
            cin >> s[i][j];
        }
    }
    
    int cnt = 0;
    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j++){
            if(s[i][j] == '#'){
                if(s[i+1][j] == '.' &&  s[i][j+1] == '.'  && s[i-1][j] == '.' && s[i][j-1] == '.'){
                    cnt++;
                }
            }
        }
    }

    if(cnt == 0) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}