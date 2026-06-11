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

void incr(vector<ll>& b, ll a) {
    rep(i, b.size()) {
        if (a & (1LL << i)) {
            b[i]++;
        }
    }
}

void decr(vector<ll>& b, ll a) {
    rep(i, b.size()) {
        if (a & (1LL << i)) {
            b[i]--;
        }
    }
}

bool update(vector<ll>& b, ll a) {
    incr(b, a);
    rep(i, b.size()) {
        if (b[i] > 1) {
            return false;
        }
    }
    return true;
}

void Main()
{
    ll n;
    cin >> n;
    vector<ll> A(n);
    rep(i, n) cin >> A[i];

    vector<ll> b(30);

    ll res = 0;
    ll j = 0;
    rep(i, n) {
        while (j < n && update(b, A[j])) {
            j++;
        }

        res += j - i;

        if (i == j) {
            j++;
        }

        decr(b, A[i]);
        if (i != j) {
            decr(b, A[j]);
        }
    }

    put(res);
}
signed main(){ Main();return 0;}