#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//cout << fixed << setprecision(17) << res << endl;
 
int main() {
    ll d, n;
    cin >> d >> n;
    ll k = 1;
    if (n == 100) ++n;
    for (ll i = 0; i < d; ++i) {
        k *= 100;
    }
    cout << n * k << endl;
}
