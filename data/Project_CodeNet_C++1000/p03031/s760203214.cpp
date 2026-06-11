#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define VB vector<bool>
#define VVL vector<vector<ll>>

int main(){
    ll N, M;
    cin >> N >> M;
    VL k(M);
    VVL s(M, VL(N,0));
    rep(i,0,M){
        cin >> k[i];
        rep(j,0,k[i]){
            cin >> s[i][j];
            s[i][j]--;
        }
    }
    VL p(M);
    rep(i,0,M)cin >> p[i];
    
    ll ans = 0;
    rep(bit, 0, 1LL<<N){
        VB sw(N, false);
        rep(i, 0, N){
            if(bit & 1LL<<i) sw[i] = true;
        }
        ll c = 0;
        rep(i, 0, M){
            ll ctmp = 0;
            rep(j, 0, k[i]){
                if(sw[s[i][j]]) ctmp++;
            }
            if(ctmp%2 == p[i]) c++;
        }
        if(c == M) ans++;
    }
 	cout << ans << endl;
    return 0;
}