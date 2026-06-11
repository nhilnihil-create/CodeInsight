#include <bits/stdc++.h>
//#include "atcoder/all"
typedef long long int ll;
using namespace std;
// using namespace atcoder;
int main() {
    int n;
    cin >> n;
    ll a[n + 1], b[n + 1];
    ll suma = 0;
    ll sumb = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        suma += a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        sumb += b[i];
    }
    ll k = sumb - suma;
    for (int i = 1; i <= n; i++) {
        if (b[i] - a[i] > 0) {
            k -= (b[i] - a[i] + 1) / 2;
        }
    }
    if (k < 0) {
        cout << "No" << endl;
    }
    else {
        cout << "Yes" << endl;
    }
    return 0;
}