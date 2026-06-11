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
signed main()
{
    int n;
    cin >> n;

    int v = n;
    for (int i = 0; i <= n; i++) {
        int c = 0;
        int t = i;
        while (t > 0) {
            c += t % 6;
            t /= 6;
        }
        t = n - i;
        while (t > 0) {
            c += t % 9;
            t /= 9;
        }
        v = min(v, c);
    }

    put(v);

    return 0;
}