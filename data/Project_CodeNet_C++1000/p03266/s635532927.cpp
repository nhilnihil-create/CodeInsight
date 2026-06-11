#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int n, k;
    cin >> n >> k;
    ll ans = pow(n/k,3);
    if (k&1) cout << ans << endl;
    else {
        ans += pow(n/(k/2)-n/k,3);
        cout << ans << endl;
    }
}