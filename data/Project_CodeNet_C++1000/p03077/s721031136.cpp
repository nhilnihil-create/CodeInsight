#include <bits/stdc++.h>
using namespace std;
constexpr long long MOD = 1000000007;
using ll = long long;
int main() {
    ll n, a, b, c, d, e;
    cin >> n >> a >> b >> c >> d >> e;
    cout << (n + min({a, b, c, d, e}) - 1) / min({a, b, c, d, e}) + 4 << endl;
}
