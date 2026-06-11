#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;

int main(void)
{
    int H,W,ans = 0,cnt = 0;
    cin >> H >> W;
    string s[H];

    vector<vector<char>> S(H, vector<char>(W));

    rep(i, H){
        cin >> s[i];
    }

    rep(i,H){
        rep(j,W){
            if(s[i][j] == '.'){
                cnt = 0;
                for(int a = i-1;a <= i+1;a++){
                    for(int b = j-1;b <= j+1;b++){
                        if(a >= 0 && a < H && b >= 0 && b < W && s[a][b] == '#')
                            cnt++;
                    }
                }
                char c = '0' + cnt;
                s[i][j] = c;
            }
        }
    }

    rep(i,H){
        cout << s[i] << endl;
    }

    return 0;
}