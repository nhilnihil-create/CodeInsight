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
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    vector<ll> b(n);
    rep(i, n) b[i] = abs(a[i]);
    ll ind = max_element(all(b)) - b.begin();

    ll cnt = 0;

    if (a[ind] == 0) {
        put(0);
        return;
    }

    typedef pair<ll, ll> P;
    vector<P> res;

    ll d = a[ind];

    if (a[ind] > 0) {
        for (int i = 1; i < n; i++) {
            while (a[i-1] > a[i]) {
                a[i] += d;
                cnt++;
                
                res.push_back(P(i+1, ind+1));

                if (a[i] > d) {
                    d = a[i];
                    ind = i;
                }
            }
        }
    }
    else {
        for (int i = n - 2; i >= 0; i--) {
            while (a[i] > a[i + 1]) {
                a[i] += d;
                cnt++;
                
                res.push_back(P(i+1, ind+1));
                if (a[i] < d) {
                    d = a[i];
                    ind = i;
                }
            }
        }
    }


    put(res.size());
    rep(i, res.size()) {
        cout << res[i].second << " " << res[i].first << endl;
    }

}
signed main(){ Main();return 0;}