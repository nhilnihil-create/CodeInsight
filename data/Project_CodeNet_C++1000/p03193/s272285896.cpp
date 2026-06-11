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
    int n, h, w; cin >> n >> h >> w;
    int ans = 0;
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        if(h <= a && w <= b) ans++;
    }
    cout << ans << endl;

    return 0;
}
