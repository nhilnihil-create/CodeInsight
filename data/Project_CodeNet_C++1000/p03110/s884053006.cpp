#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)

signed main()
{
    int n; cin >> n;
    vector<double> x(n);
    vector<string> u(n);
    rep(i,n) cin >> x[i] >> u[i];

    double ans = 0;
    rep(i,n){
        if (u[i]=="JPY")
            ans += x[i];
        else
            ans += x[i] * 380000;
    }

    cout << fixed << setprecision(9);
    cout << ans << endl;

    return 0;
}
