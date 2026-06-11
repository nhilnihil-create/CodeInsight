#include <bits/stdc++.h>
// #include <atcoder/all>
#define ll long long int
#define ld long double
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, n) for (ll i = 1; i < (ll)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
// using namespace atcoder;


// Eratosthenes
vector<int> eratTable;

vector<ll> eratosthenes(ll n) {
    eratTable.assign(n + 1, 1);
    eratTable[0] = 0;
    eratTable[1] = 0;
    for (ll i = 2; i <= n; i++) {
        if (eratTable[i] == 1) {
            for (ll j = 2; i * j <= n; j++) {
                eratTable[i * j] = 0;
            }
        }
    }

    vector<ll> primes;
    rep(i, eratTable.size()) {
        if (eratTable[i] >= 1) {
            primes.push_back(i);
        }
    }

    return primes;
}

void Main()
{
    ll Q;
    cin >> Q;
    vector<ll> l(Q), r(Q);
    rep(i, Q) cin >> l[i] >> r[i];

    auto primes = eratosthenes(100001);

    vector<ll> S(100001);
    ll cnt = 0;
    rep(i, 100001) {
        if (2 == i) {
            continue;
        }
        if (eratTable[i] == 1) {
            ll v = (i + 1) / 2;
            if (eratTable[v] == 1) {
                cnt++;
            }
        }

        S[i] = cnt;
    }

    rep(i, Q) {
        put(S[r[i]] - S[l[i] - 1]);
    }

}
signed main(){ Main();return 0;}