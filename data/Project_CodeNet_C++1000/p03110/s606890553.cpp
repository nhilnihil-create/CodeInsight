#include <bits/stdc++.h>
#define ll long long int
#define ld long double
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
    vector<ld> x(n);
    vector<string> u(n);
    rep(i, n) cin >> x[i] >> u[i];

    long double sum = 0;
    rep(i, n) {
        if (u[i] == "JPY") {
            sum += x[i];
        }
        else {
            sum += x[i] * 380000.0;
        }
    }

    put(sum)
    
    return 0;
}