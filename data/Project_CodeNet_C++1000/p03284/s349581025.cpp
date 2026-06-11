#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//cout << fixed << setprecision(17) << res << endl;
 
int main() {
    ll n, k;
    cin >> n >> k;
    if ((n % k) == 0) {
        cout << 0 << endl;
    } else {
        cout << 1 << endl;
    }
}
