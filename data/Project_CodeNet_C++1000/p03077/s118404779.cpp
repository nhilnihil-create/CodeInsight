#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
ll MOD = 1e9 + 7;

int main() {
    ll n, a, b, c, d, e;
    cin >> n >> a >> b >> c >> d >> e;
    ll min_ = INF;
    min_ = min(a, min(b, min(c, min(d, e))));
    cout << (n - 1) / min_ + 5 << endl;
    return 0;
}