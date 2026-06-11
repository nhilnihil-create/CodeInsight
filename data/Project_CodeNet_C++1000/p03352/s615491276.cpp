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
    int x;
    cin >> x;
    int best = 1;
    rep(b_, sqrt(x)) {
        int b = b_ + 1;
        rep(p_, 1000) {
            int p = p_ + 2;
            int v = 1;
            rep(i, p) v *= b;
            if (v > x) {
                break;
            }
            // put(b)
            // put(p)
            // put(v)
            // put("--")
            best = max(best, v);
        }
    }
    put(best)
    return 0;
}