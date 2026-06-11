#include<bits//stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long int ll;
ll h, m, n;
ll sum = 0;
int main() {
    cin >> n; vector<int> k(n);
    rep(i, n) {
        ll a, b;cin >> a >> b;
        sum += b;
        k[i] = a + b;
    }
    sort(k.rbegin(),k.rend());
    ll ans = 0;
    for (int i = 0; i < n; i += 2) {
        ans += k[i];
    }
    cout << ans - sum << endl;
}