#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = (1<<29);
const int INFF = 0x7fffffff;
const ll LINF = (1ll<<60);
const ll LINFF = 0x7fffffffffffffff;
const long double PI = 3.14159265359;

#define _fi(n) for(int i = 0;i < n;i++)
#define _fj(n) for(int j = 0;j < n;j++)
#define _fk(n) for(int k = 0;k < n;k++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define prec(x) cout << fixed << setprecision(x)
#define sz(x) (int)x.size()
#define _log2(x) 31-__builtin_clz(x)

#define hash sodnf9843bsd
#define right iadjfof23n3okd
#define pqueue priority_queue
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define len length
#define endl '\n'

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rnd(ll a, ll b){return uniform_int_distribution<ll>(a, b)(rng);}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<double>p(n);
    _fi(n) cin>>p[i];

    double dp[3030] = {};
    dp[0] = 1;
    for(int coin = 0;coin < n;coin++){
        for(int h = n;h >= 0;h--){
            dp[h] = (1-p[coin])*dp[h];
            if (h > 0) dp[h] += p[coin]*dp[h-1];
        }
    }

    double ans = 0;
    for(int h = 1;h <= n;h++){
        if (h > n-h) ans += dp[h];
    }

    prec(10);
    cout << ans << endl;

    return 0;
}
