#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long;
#define INF 1e9
int main() {
    ll X, Y;
    cin >> X >> Y;
    ll ans = 0;
    for (ll i = 0; i < INF; ++i) {
        if (X <= Y) {
            ans++;
        }
        else {
            break;
        }
        X *= 2;
    }
    cout << ans << endl;
    return 0;
}