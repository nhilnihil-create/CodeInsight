#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, n) for (int i = 1; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;


ll gcd(ll a, ll b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

int main()
{
    ll n, x;
    cin >> n >> x;
    vector<ll> X(n);
    rep(i, n) cin >> X[i];

    vector<ll> d(n);
    rep(i, n) d[i] = abs(X[i] - x);
    ll ans = d[0];
    rep(i, n -1) ans= gcd(ans, d[i+1]);
    put(ans)

    return 0;
}