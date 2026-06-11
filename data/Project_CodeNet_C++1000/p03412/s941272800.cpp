#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 1000000000;
const ll LINF = (ll) 4000000000000000000;
const ll MOD = (ll) 1000000007;
const double PI = acos(1.0);
const int limit = 100010;

#define REP(i,m,n) for(int i = (int)m; i < (int)n; i++)
#define rep(i,n) REP(i,0,n)
#define rep2(i,n) REP(i,1,n+1)
#define rep3(i,n) REP(i,0,n+1)
#define REPM(i,m,n) for(int i = (int)m; i >= (int)n; i--)
#define REPLL(i,m,n) for(ll i=m;i<(ll)(n);i++)
#define repll(i,n) REPLL(i,0,n)
#define repll2(i,n) REPLL(i,1,n+1)
#define MP make_pair
#define YES(n) cout << ((n) ? "YES" : "NO") << endl
#define Yes(n) cout << ((n) ? "Yes" : "No") << endl
#define Possible(n) cout << ((n) ? "Possible" : "Impossible") << endl
#define NP(v) next_permutation(v.begin(),v.end())
#define Size(s) (int) s.size()

//------------------------------------------------------

int main() {
    int n;
    cin >> n;
    ll a[n], b[n];
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];

    ll sum = 0;

    rep(k, 32) { //k-bitを求める
        ll cnt = 0;

        ll k_pow = (1 << k);
        ll k_mod = (1 << (k + 1));

        ll b_mod[n];
        rep(i, n) b_mod[i] = b[i] % k_mod;
        sort(b_mod, b_mod + n);

        rep(i, n) {
            ll ai_mod = a[i] % k_mod;

            cnt += lower_bound(b_mod, b_mod + n, 2 * k_pow - ai_mod)
                    - lower_bound(b_mod, b_mod + n, k_pow - ai_mod);
            cnt += lower_bound(b_mod, b_mod + n, 4 * k_pow - ai_mod)
                    - lower_bound(b_mod, b_mod + n, 3 * k_pow - ai_mod);
        }
        sum += (cnt % 2) * k_pow;
    }

    cout << sum << endl;

    return 0;
}