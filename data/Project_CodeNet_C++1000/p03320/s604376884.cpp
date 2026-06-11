#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 1000000000;
const ll LINF = (ll) 4000000000000000000;
const ll MOD = (ll) 1000000007;
const double PI = acos(1.0);
const int limit = 100010;

#define REP(i,m,n) for(ll i = m; i < (ll)(n); i++)
#define rep(i,n) REP(i, 0, n)
#define MP make_pair
#define YES(n) cout << ((n) ? "YES" : "NO") << endl
#define Yes(n) cout << ((n) ? "Yes" : "No") << endl
#define Possible(n) cout << ((n) ? "Possible" : "Impossible") << endl
#define NP(v) next_permutation(v.begin(),v.end())
#define smaller_queue  priority_queue <ll, vector<ll>, greater<ll> >
//------------------------------------------------------

ll digit_sum(ll n) {
    ll res = 0;
    while (n != 0) {
        res += n % 10;
        n /= 10;
    }
    return res;
}

bool NG_jugde(ll n, ll m) {
    return (ld) n / (ld) digit_sum(n) > (ld) m / (ld) digit_sum(m);
}

int main() {
    ll k;
    cin >> k;

    set<ll> st;
    ll base = 1;

    rep(i, 15) {

        REP(i, 1, 1000) {
            st.insert(i * base - 1);
        }

        base *= 10;
    }

    vector<ll> ans;
    auto itr = st.begin();

    rep(i, st.size()) {
        if (*itr == 0) {
            itr++;
            continue;
        }
        bool ok = true;
        auto itr2 = itr;
        itr2++;

        REP(j, i + 1, st.size()) {
            if (NG_jugde(*itr, *itr2)) {
                ok = false;
                break;
            }
            itr2++;
        }
        if (ok) ans.push_back(*itr);
        itr++;
    }

    rep(i, k) cout << ans[i] << endl;

    return 0;
}

