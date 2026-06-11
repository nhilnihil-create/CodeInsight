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
    vector<int> c(9);
    rep(i, 9) cin >> c[i];

    vector<int> x(3);
    vector<int> y(3);
    repi(i, 3) x[i] = c[i] - c[i-1];
    repi(i, 3) y[i] = c[3 * i] - c[3 * (i - 1)];
    
    rep(i, 3) {
        repi (j, 3) {
            if (c[3 * i + j] - c[3 * i + j - 1] != c[3 * 0 + j] - c[3 * 0 + j - 1]){
                put("No");
                return 0;
            }
        }
    }
    
    repi(i, 3) {
        rep (j, 3) {
            if (c[3 * i + j] - c[3 * (i - 1) + j] != c[3 * i + 0] - c[3 * (i - 1) + 0]){
                put("No");
                return 0;
            }
        }
    }

    put("Yes");

    return 0;
}