#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//cout << fixed << setprecision(17) << res << endl;
 
int main() {
    ll a, b;
    cin >> a >> b;
    ll t = 0;
    for (ll i = b - a; i > 0; --i) t += i;
    cout << t - b << endl;
}
