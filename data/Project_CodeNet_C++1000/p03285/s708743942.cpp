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
    for (int i = 0; ; i++) {
        if (7 * i > n) {
            break;
        }
        if ((n - 7 * i) % 4 == 0) {
            put("Yes");
            return 0;
        }
    }
    put("No")
    return 0;
}