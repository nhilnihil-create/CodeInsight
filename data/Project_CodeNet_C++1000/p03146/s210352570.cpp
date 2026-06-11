#include <bits/stdc++.h>
#define ll long long int
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
signed main()
{
    ll n;
    cin >> n;
    
    unordered_set<ll> us;
    us.emplace(n);
    for (int i = 0; ; i++) {
        n = n % 2 == 0 ? n / 2 : 3 * n + 1;
        if (us.count(n) >= 1) {
            cout << i + 2 << endl;
            return 0;
        }
        us.emplace(n);
    }

    return 0;
}