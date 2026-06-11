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
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) {
            continue;
        }
        int cnt = 0;
        for (int j = 1; j <= i; j++) {
            if (i % j == 0) {
                cnt ++;
            }
        }
        if (cnt == 8) {
            ans ++;
        }
    }
    put(ans)
    return 0;
}