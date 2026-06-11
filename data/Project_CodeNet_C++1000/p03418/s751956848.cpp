#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    int n, k;
    cin >> n >> k;
    if(k == 0) {
        cout << (ll)n * n << endl;
        return 0;
    }

    ll ans = 0;
    for(int i = k + 1; i <= n; i++){
        ans += (n / i) * (i - k);
        ans += max(0, n % i - k + 1);
    }
    cout << ans << endl;
}