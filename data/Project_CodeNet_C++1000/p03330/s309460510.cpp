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
    VVL D(C, VL(C)), c(N, VL(N));
    rep(i, 0, C){
        rep(j, 0, C) cin >> D[i][j];
    }

    VVL acc(3, VL(C, 0));
    rep(i, 0, N){
        rep(j, 0, N){
            cin >> c[i][j];
            c[i][j]--;
            acc[(i+j+2)%3][c[i][j]]++;
        }
    }

    ll ans = 1e18;
    rep(i, 0, C){
        ll s1 = 0;
        rep(l, 0, acc[0].size()){
            s1 += acc[0][l] * D[l][i];
        }
        rep(j, 0, C){
            if(i == j) continue;
            ll s2 = 0;
            rep(l, 0, acc[1].size()){
                s2 += acc[1][l] * D[l][j];
            }
            rep(k, 0, C){
                if(i == k || j == k) continue;
                ll s3 = 0;
                rep(l, 0, acc[2].size()){
                    s3 += acc[2][l] * D[l][k];
                }
                ans = min(ans, s1+s2+s3);
            }  
        }
    }

    cout << ans << endl;
    return 0;
}