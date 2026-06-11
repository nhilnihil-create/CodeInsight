#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define VS vector<string>
#define VB vector<bool>
#define VP vector<pair<ll,ll>>
#define VVL vector<vector<ll>>
#define VVP vector<vector<pair<ll,ll>>>
#define PL pair<ll,ll>
#define ALL(v) (v).begin(), (v).end()
ll d1[4] = {1, -1, 0, 0};
ll d2[4] = {0, 0, 1, -1};

int main(){
    ll N, C;
    cin >> N >> C;
    VVL d(C+1, VL(C+1));
    rep(i, 1, C+1){
        rep(j, 1, C+1){
            cin >> d[i][j];
        }
    }
    /*
    rep(i, 1, C+1) d[i][i] = 0;
    rep(i, 1, C+1){
        rep(j, 1, C+1){
            rep(k, 1, C+1){
                d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
            }
        }
    }
    */
    
    VVL c(N+1, VL(N+1));
    VVL cnt(3, VL(C+1,0));
    rep(i, 1, N+1){
        rep(j, 1, N+1){
            cin >> c[i][j];
            cnt[(i+j)%3][c[i][j]]++;
        }
    }

    ll ans = 1e18;
    rep(z, 1, C+1){
        rep(o, 1, C+1){
            if(z == o) continue;
            rep(t, 1, C+1){
                if(z == t || o == t) continue;
                ll tmp = 0;
                rep(cc, 1, C+1){
                    tmp += cnt[0][cc] * d[cc][z] + cnt[1][cc] * d[cc][o] + cnt[2][cc] * d[cc][t];
                }
                ans = min(tmp, ans);
            }
        }
    }

    cout << ans << endl;
    return 0;
}