#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    vector<double> x(n);
    vector<string> u(n);
    rep(i,n) cin >> x[i] >> u[i];
    int sum_jpy = 0;
    double sum_btc = 0;
    rep(i,n){
        if(u[i] == "JPY") sum_jpy += x[i];
        else sum_btc += x[i];
    }

    double ans = sum_jpy + 380000*sum_btc;

    cout << fixed << setprecision(10);
    cout << ans << endl;
}
