#include <bits/stdc++.h>
#define ll long long 
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; 
   // cin >> t;
    for(int T = 0; T < t ; T++){
        ll h, w;
        cin >> h >> w;
        ll a[h][w], mod = 1e9 + 7;
        string s[h];
        for(int i = 0; i < h; i++){
            cin >> s[i];
        }
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                a[i][j] = 0;
            }
        }
        for(int i = 0; i < h; i++){
            if(s[i][0] == '.')
                a[i][0] = 1;
            else{
                break;
            }
        }
        for(int i = 0; i < w; i++){
            if(s[0][i] == '.')
                a[0][i] = 1;
            else{
                break;
            }
        }
        for(int i = 1; i < h; i++){
            for(int j = 1; j < w; j++){
                if(s[i][j] == '#')
                    a[i][j] = 0;
                else
                    a[i][j] = (a[i - 1][j] + a[i][j -1])%mod;
            }
        }
        if(s[0][0] == '.')
        cout << a[h - 1][w - 1] << endl;
        else
        cout << 0 << endl;
    }
    return 0;
}