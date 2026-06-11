#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
//cout << setprecision(20) << 

int main() {
    vector<int> a(4);
    a[0] = 0;
    for (int i = 1; i <= 3; ++i) cin >> a[i];
    sort(a.begin(), a.end());

    ll ans = 0;
    do {
        if (a[0] == 0 || a[3] == 0) continue; 
        ll tmp;
        if (a[1] == 0) {
            tmp = a[0] + 10 * a[2] + a[3];
        }
        else {
            tmp = 10 * a[0] + a[1] + a[3];
        }
        ans = max(ans, tmp);
    } while (next_permutation(a.begin(), a.end()));
    cout << ans << endl;
}