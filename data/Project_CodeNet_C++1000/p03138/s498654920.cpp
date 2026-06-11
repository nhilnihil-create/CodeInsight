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

ll calc(ll x, ll d, const vector<ll>& A) {
    // 1~d桁まで見て、xを自由に決める
    rep(i, d) {
        ll one = 0, zero = 0;
        rep(j, A.size()) {
            if ((A[j] >> (d - 1 - i)) & 1) {
                one++;
            }
            else {
                zero++;
            }
        }
        if (one > zero) {
            x = x * 2 + 0;
        }
        else {
            x = x * 2 + 1;
        }
    }
    return x;
}

ll xorA(ll x, const vector<ll>& A) {
    ll v = 0;
    rep(i, A.size()) {
        v += x ^ A[i];
    }
    return v;
}

ll dfs(ll x, ll d, ll K, const vector<ll>& A) {
    if (d <= 0) {
        return x;
    }
    if ((K & (1LL << (d-1))) == 0) {
        // xのdビット目は0
        x = dfs(2 * x, d - 1, K, A);
        return x;
    }
    if (K == (1LL << d) - 1) {
        x = calc(x, d, A);
        return x;
    }

    ll x1 = dfs(2 * x + 1, d - 1, K - (1LL << (d - 1)), A);
    ll v1 = xorA(x1, A);

    ll x2 = 2 * x + 0;
    x2 = calc(x2, d - 1, A);
    ll v2 = xorA(x2, A);

    if (v1 > v2) {
        return x1;
    }
    return x2;
}


void Main()
{
    ll n, K;
    cin >> n >> K;
    vector<ll> A(n);
    rep(i, n) cin >> A[i];

    ll digit = 0;
    for (ll t = K; t > 0; t /= 2) digit++;
    
    ll x = dfs(0, digit, K, A);
    ll res = xorA(x, A);
    put(res);
}
signed main(){ Main();return 0;}