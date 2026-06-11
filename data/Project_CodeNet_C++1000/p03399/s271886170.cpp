#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int ans = 0;
    if(a < b) ans += a;
    else ans += b;
    if(c < d) ans += c;
    else ans += d;
    cout << ans << endl;
}