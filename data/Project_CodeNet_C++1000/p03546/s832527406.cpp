#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int H, W; cin >> H >> W;
    int c[10][10];
    int C[10][10];
    rep(i, 10){
        rep(j, 10){
            cin >> c[i][j];
            C[i][j] = c[i][j];
        }
    }

    for (int k = 0; k < 10; k++){
        for (int i = 0; i < 10; i++){
            for (int j = 0; j < 10; j++){
                C[i][j] = min(C[i][j], C[i][k] + C[k][j]);
            }
        }
    }

    int ans = 0;
    rep(i, H){
        rep(j, W){
            int a; cin >> a;
            if(a == -1)continue;
            ans += C[a][1];
        }
    }

    cout << ans << endl;

    return 0;
}