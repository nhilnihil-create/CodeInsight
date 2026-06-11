#include<bits/stdc++.h>
// #define int long long
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
#define MOD 1000000007
using namespace std;
using ll = long long;
typedef vector<int> vi;

signed main() {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];
    vector<vector<int>> tmp(h+2, vi(w+2));

    rep(i, h){
        rep(j, w){
            if(s[i][j] == '#'){
                for(int k = -1; k <= 1; k++){
                    if(i == 0 && k == -1) continue;
                    for(int l = -1; l <= 1; l++){
                        if(j == 0 && l == -1) continue;
                        tmp[i+k][j+l]++;
                    }
                }
            }
        }
    }

    rep(i, h){
        rep(j, w){
            if(s[i][j] == '#'){
                cout << '#';
            }else{
                cout << tmp[i][j];
            }
        }
        cout << endl;
    }
    return 0;
}