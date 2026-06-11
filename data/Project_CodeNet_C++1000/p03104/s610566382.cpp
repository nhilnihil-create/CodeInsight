#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
//cout << setprecision(20) << 

ll f(ll n) {
    if (n < 0) return 0;
    ll count = ceil((double)n/2);
    // (0 xor 1) xor ... (n-1 xor n)
    if (n % 2 == 1) {
        return count % 2;
    }
    // (0 xor 1) xor ... (n-2 xor n-1) xor n
    else {
        return n ^ (count % 2);
    }
}

int main() {
    ll A, B; cin >> A >> B;
    ll ans = f(B) ^ f(A-1);
    cout << ans << endl;
}