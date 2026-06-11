#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)
#define repp(i, n, m) for(int (i) = (n); (i) < (m); (i)++)
#define repn(i, n) for(int (i) = 1; (i) <= (n); (i)++)
#define repr(i, n) for(int (i) = (n-1); (i) >= 0; (i)--)
#define all(x) (x).begin(), (x).end()
#define lint long long
#define ulint unsigned long long
#define ldou long double
#define fi first
#define se second
#define setpre(x) std::cout << fixed << setprecision(x)
#define ii(x) int x; cin >> (x)
#define ii2(x, y) int x, y; cin >> (x) >> (y)
#define ii3(x, y, z) int x, y, z; cin >> (x) >> (y) >> (z)
#define out(x) cout << (x) << endl
#define outs(x) cout << (x) << " "
#define yn(x) cout << ((x)?("Yes"):("No")) << endl
#define YN(x) cout << ((x)?("YES"):("NO")) << endl
#define bit_c(x) __builtin_popcountll(x)

inline void logger(){ std::cout << " [LOGGER] " << endl; }
template<typename A, typename... B>
void logger(const A& a, const B&... b){
    cout << a << " , ";
    logger(b...);
}

typedef pair<lint, lint> P;
const lint MOD = 1000000007;
const lint MOD9 = 998244353;
const lint INF = MOD * MOD;
const int MAX = 3005;

/* ...o(^-^)o... */
lint a[17][17];
lint dp[1<<17];

int main(){
    int n; cin >> n;
    rep(i, n) rep(j, n) cin >> a[i][j];
    rep(s, 1<<n){
        rep(i, n-1) repp(j, i+1, n){
            if(s&(1<<i) && s&(1<<j)) dp[s] += a[i][j];
        }
        dp[s] = max(dp[s], 0LL);
        for(int t = (s-1)&s; t>0; t=(t-1)&s){
            int u = s^t;
            dp[s] = max(dp[s], dp[t]+dp[u]);
        }
    }
    out(dp[(1<<n)-1]);
}
