#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;
typedef pair<int, int> P;

const ll mod =  1000000007;  //ansを出力する時は (ans % mod + mod) % mod とする(負の剰余を正にする)
const int inf = 1e9;
const long long INF = 1LL << 60;   // INFの値は1152921504606846976


int n,c;
const int V_MAX = 505;
ll d[V_MAX][V_MAX];



int main()
{
    cin >> n >> c;
    rep(i,c) rep(j,c) cin >> d[i][j];
    ll g[n][n];
    rep(i,n) {
        rep(j,n){
            cin >> g[i][j];
            g[i][j]--;
        }
    }
    ll ans = INF;
    ll mod0[c],mod1[c],mod2[c];
    rep(i,c){
        mod0[i] = 0;
        mod1[i] = 0;
        mod2[i] = 0;
    }
    rep(i,c){
        rep(y,n){
            rep(x,n){
                if((x+y) % 3 == 0) mod0[i] += d[g[y][x]][i];
                else if((x+y) % 3 == 1) mod1[i] += d[g[y][x]][i];
                else mod2[i] += d[g[y][x]][i];
            }
        }
    }
    for(int i = 0; i < c; i++){
        for(int j = 0; j < c; j++){
            if(i == j) continue;
            for(int k = 0; k < c; k++){
                if(k == j || i == k) continue;
                ans = min(ans,mod0[i] + mod1[j] + mod2[k]);
            }
        }
    }
    cout << ans << endl;
}