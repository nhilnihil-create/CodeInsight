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
int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    while (true) {
        ll mind = -1;
        ll mi = 1e10;
        ll live = 0;

        rep (i, n) if (a[i] > 0) {
            live++;
            if (a[i] < mi) {
                mind = i;
                mi = a[i];
            }
        }

        if (live <= 1) {
            put(mi);
            return 0;
        }

        rep (i, n) { 
            if (i != mind) {
                a[i] = a[i] % mi;
            }
        }
    }

    return 0;
}