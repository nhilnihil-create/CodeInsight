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

vector<pair<ll, ll> > prime_factorize(ll N) {
    vector<pair<ll, ll> > res;
    for (ll a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        ll ex = 0; // 指数

        // 割れる限り割り続ける
        while (N % a == 0) {
            ++ex;
            N /= a;
        }

        // その結果を push
        res.push_back({a, ex});
    }

    // 最後に残った数について
    if (N != 1) res.push_back({N, 1});
    return res;
}

ll C2(ll n) {
    if (n < 0) {
        return 0;
    }
    return n * (n - 1) / 2;
}

void Main()
{
    ll n;
    cin >> n;

    vector<ll> primeCnt(101);

    for (ll i = 2; i <= n; i++) {
        auto primes = prime_factorize(i);
        for(auto p: primes) {
            primeCnt[p.first] += p.second;
        }
    }

    // 指数がi以上の素数のかずd[i]
    vector<ll> d(101);
    rep(i, primeCnt.size()) {
        if (primeCnt[i] <= 0) {
            continue;
        }
        ll num = primeCnt[i];
        rep(i, num + 1) {
            d[i]++;
        }
    }

    ll res = d[74]; // 75
    res += C2(d[4]) * (d[2] - 2); // 5 x 5 x 3
    res += d[14] * (d[4] - 1);
    res += d[24] * (d[2] - 1);

    put(res);    
}
signed main(){ Main();return 0;}