#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;
using ld = long double;
const int MOD = 1e9+7;
const ll INF = 1LL << 60;


int main() {
    int a,b,c; cin >> a >> b >> c;
    V<int> v({a,b,c});
    sort(ALL(v));
    int ans = abs(v[1] - v[0]) + abs(v[2] - v[1]);
    cout << ans << endl;


    return 0;
}
