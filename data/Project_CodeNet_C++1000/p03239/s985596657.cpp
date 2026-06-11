#include <bits/stdc++.h>
#define ll long long int
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
int main()
{
    int n, T;
    cin >> n >> T;
    vector<int> c(n), t(n);
    rep(i, n) cin >> c[i] >> t[i];

    int best = 1e8;
    rep(i, n) {
        if (t[i] <= T) {
            if (best > c[i]) {
                best = c[i];
            }
        }
    }
    if (best == 1e8) {
        put("TLE")
    }
    else 
        put(best)

    
    return 0;
}