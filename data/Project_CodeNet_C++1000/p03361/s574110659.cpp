#include<bits/stdc++.h>
// #define int long long
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
#define MOD 1000000007
using namespace std;
using ll = long long;
typedef vector<int> vi;
#define ODD 1
#define EVEN 0

signed main() {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];
    bool bocchi = false;
    /* i means row, j means col */
    rep(i, h){
        rep(j, w){
            if(i == 0 || i == h-1 || j == 0 || j == w-1) continue;
            if(s[i][j] =='#' && s[i-1][j] == '.' && s[i][j+1] == '.' && s[i+1][j] == '.' && s[i][j-1] == '.') bocchi = true;
        }
    }
    if(!bocchi) cout << "Yes" << endl;
    else cout << "No" << endl;
}