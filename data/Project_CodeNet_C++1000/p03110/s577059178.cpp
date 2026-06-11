#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long double> x(n); //kane
    vector<string> u(n); //jpy or btc
    long double ans = 0;
    cout << fixed << setprecision(15);
    for(int i=0; i<n; i++) {
        cin >> x[i] >> u[i];
        if( u[i] == "JPY") ans += x[i];
        else {
            ans += 380000.0 * x[i];
        }
    }

    cout << ans << endl;
}