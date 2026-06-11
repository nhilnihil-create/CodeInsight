#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#define rep(i,n) for(int (i)=0;(i)<(n);++(i))
#define all(x) (x).begin(),(x).end()
#define dump(x) cout << #x << " = " << (x) << endl

using namespace std;
using ll = long long;

const ll INF = 1001001001001001001;

int main() {
    int n; cin >> n;
    vector<ll> a(n), b(n);
    rep(i, n) {
        cin >> a[i];
        b[i] = a[i] - i;
    }

    sort(all(b));
    ll x = b[n / 2];

    ll ans = 0;
    rep(i, n) ans += max(x - b[i], - x + b[i]);
    cout << ans << endl;
}