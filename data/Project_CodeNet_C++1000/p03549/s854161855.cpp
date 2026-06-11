#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
ll MOD = 1000000000 + 7;

int main() {
    int n, m;
    cin >> n >> m;
    ll ans = (1900 * m + 100 * (n - m)) * pow(2, m);
    cout << ans << endl;
    return 0;
}