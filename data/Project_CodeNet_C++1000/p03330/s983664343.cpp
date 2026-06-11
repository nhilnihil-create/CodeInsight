#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int N, C; cin >> N >> C;
    int D[C][C];
    int c[N][N];
    rep(i, C){
        rep(j, C){
            cin >> D[i][j];
        }
    }
    rep(i, N){
        rep(j, N){
            cin >> c[i][j];
        }
    }

    vector<int> iwa0(C);
    vector<int> iwa1(C);
    vector<int> iwa2(C);
    rep(k, C){
        rep(i, N){
            rep(j, N){
                int x = (i+j) % 3;
                if(x == 0){
                    iwa0[k] += D[c[i][j]-1][k];
                } else if(x == 1){
                    iwa1[k] += D[c[i][j]-1][k];
                } else {
                    iwa2[k] += D[c[i][j]-1][k];
                }
            }
        }
    }

    ll ans = 1001001001;
    rep(i, C){
        rep(j, C){
            if(j == i)continue;
            rep(k, C){
                if(k == i || k == j)continue;
                ll now = iwa0[i] + iwa1[j] + iwa2[k];
                ans = min(ans, now);
            }
        }
    }

    cout << ans << endl;

    return 0;
}