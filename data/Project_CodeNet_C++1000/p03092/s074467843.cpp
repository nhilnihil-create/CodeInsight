#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = (1<<30)-1;
const ll INF = (1LL<<60)-1;
const ld EPS = 1e-10;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

int main(){
    int N; ll A, B;
    cin >> N >> A >> B;
    int p[N], id[N];
    rep(i, N){
        cin >> p[i]; p[i]--;
        id[p[i]] = i;
    }
    int ord[N];
    rep(i, N){
        ord[i] = 1;
        rep(j, i) if(id[j] < id[i]) ord[i]++;
    }
    ll dp[N+1][N+1];
    fill(dp[0], dp[N+1], INF);
    dp[0][0] = 0;
    rep(i, N){
        rep(j, ord[i]) dp[i+1][j] = dp[i][j];
        rep2(j, ord[i], i+1){
            dp[i+1][j] = min(dp[i][j-1]+A, dp[i][ord[i]-1]+B*(j-ord[i]));
        }
    }
    cout << dp[N][N] << endl;
}