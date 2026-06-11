#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
#define MOD 1000000007
using namespace std;
int main() {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    ll k = 0, dif1 = 0, dif2 = 0;
    for (int i = 0; i < n; i++) {
        k += b[i] - a[i];
        if (a[i] < b[i]) {
            dif1 += (b[i] - a[i] + 1) / 2;
        } else {
            dif2 += a[i] - b[i];
        }
    }
    if (max(dif1, dif2) <= k) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
