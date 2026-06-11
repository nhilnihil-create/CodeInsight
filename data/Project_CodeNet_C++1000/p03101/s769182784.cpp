/*
    Author - Param Kothari
    Ah shit, here we go again
*/

#include <bits/stdc++.h>
 
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define mk make_pair

typedef long long ll;
typedef long double ld;

void solve(){
    int H, W;
    cin >> H >> W;
    int h, w;
    cin >> h >> w;
    int a[H][W] = {};
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            a[i][j] = 0;
        }
    }
    for(int i = 0; i < h; i++){
        for(int j = 0; j < W; j++){
            a[i][j] = 1;
        }
    }
    for(int i = 0; i < w; i++){
        for(int j = 0; j < H; j++){
            a[j][i] = 1;
        }
    }
    int res = 0;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            res += (a[i][j] == 0);
        }
    }
    cout << res << "\n";
    return;
}

int main(){
    IOS;
    int t = 1;
    // cin >> t;
    for(int i = 1; i <= t; i++){
        solve();
    }
    return 0;
}