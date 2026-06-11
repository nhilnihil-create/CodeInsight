#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp setprecision
#define pb(x) push_back(x)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<ld, ld> pdd;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = 1e8;
const ll INF = 1e16;
const string alpha = "abcdefghijklmnopqrstuvwxyz";

int main(){
    int N, C;
    cin >> N >> C;
    ll D[C][C];
    int c[N][N];
    rep(i, C) rep(j, C) cin >> D[i][j];
    rep(i, N) rep(j, N){
        cin >> c[i][j];
        c[i][j]--;
    }
    ll ans = INF;
    ll cost[3][C];
    fill(cost[0], cost[3], 0);
    rep(j, 3){
        rep(i, C){
            rep(x, N) rep(y, N){
                int nowc = c[x][y];
                if((x+y)%3 == j) cost[j][i] += D[nowc][i];
            }
        }
    }
    rep(i, C){
        rep(j, C){
            rep(k, C){
                if((i-j)*(j-k)*(k-i) == 0) continue;
                ll sum = cost[0][i] + cost[1][j] + cost[2][k];
                ans = min(ans, sum);
            }
        }
    }
    cout << ans << endl;
}