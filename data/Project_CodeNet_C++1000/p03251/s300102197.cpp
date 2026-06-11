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
    int n, m, X, Y;
    cin >> n >> m >> X >> Y;
    vector<int> x(n);
    rep(i, n) cin >> x[i];
    vector<int> y(m);
    rep(i, m) cin >> y[i];
    
    for (int z = X + 1; z <= Y; z++) {
        bool ok = true;
        rep(i, n) {
            if (x[i] < z) {
            }
            else {
                ok = false;
                break;
            }
        }
        rep(i, m) {
            if (y[i] >= z) {
            }
            else {
                ok = false;
                break;
            }
        }
        if (ok) {
            put("No War")
            return 0;
        }
    }
    
            put("War")
    
    return 0;
}