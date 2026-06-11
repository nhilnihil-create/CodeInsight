#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
//cout << setprecision(20) << 

int main() {
    ll A, B, C; cin >> A >> B >> C;
    ll ans = 0;
    if (A * C < B) ans = C;
    else ans = B/A;
    cout << ans << endl;
}