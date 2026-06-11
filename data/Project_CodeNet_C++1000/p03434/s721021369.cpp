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
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    sort(all(a));
    reverse(all(a));
    int x = 0, y = 0;
    rep(i, a.size()) {
        if (i % 2 == 0) {
            x += a[i];
        }
        else {
            y += a[i];
        }
    }
    put(x - y);
    return 0;
}