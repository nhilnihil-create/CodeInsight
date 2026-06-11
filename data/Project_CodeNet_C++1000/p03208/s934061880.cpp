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

void dump(vector<ll> v) {
    rep(i, v.size()) cout << v[i] << " ";
    cout << endl;
}


int main()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> h(n);
    rep(i, n) cin >> h[i];

    sort(all(h));
   // dump(h);
    ll best = 1e10;
    rep(i, n - k + 1) {
        best = min(best, h[i + k - 1] - h[i]);
    }
    put(best);

    return 0;
}