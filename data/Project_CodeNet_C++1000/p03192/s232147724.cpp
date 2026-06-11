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
    int n; cin >> n;
    int ans = 0;
    while(0 < n){
        if(n % 10 == 2) ans++;
        n /= 10;
    }
    cout << ans << endl;

    return 0;
}
