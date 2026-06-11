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
void Main()
{
    ll n, m;
    cin >> n >> m;

    vector<ll> A(n);
    rep(i, n) cin >> A[i];
    
    vector<ll> S(n + 1);
    rep(i, n) {
        S[i+1] = (S[i] + A[i]) % m;
    }

    unordered_map<ll,ll> cnt;
    rep(i, n) {
        cnt[S[i]] = 0;
    }

    ll res = 0;
    for (int r = 0; r <= n; r++) {
        ll sr = S[r];
        ll sl = sr;
        res += cnt[sr];
        cnt[sr]++;
    }

    put(res);
}
signed main(){ Main();return 0;}