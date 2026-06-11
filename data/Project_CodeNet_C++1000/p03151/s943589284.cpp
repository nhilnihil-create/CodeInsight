#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stack>
#include <set>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
//ll mod = 998244353;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main() {
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    ll suma = 0;
    ll sumb = 0;
    rep(i, n) {
        cin >> a[i];
        suma += a[i];
    }
    rep(i, n) {
        cin >> b[i];
        sumb += b[i];
    }
    if (suma < sumb) {
        cout << -1 << endl;
        return 0;
    }
    vector<ll> dif(n);
    rep(i, n) {
        dif[i] = a[i] - b[i];
    }
    sort(dif.begin(), dif.end());
    ll now_sum = 0;
    int ans = 0;
    rep(i, n) {
        if (dif[i] < 0) {
            now_sum += abs(dif[i]);
            ++ans;
        }
    }
    //cout << now_sum << endl;
    reverse(dif.begin(), dif.end());
    rep(i, n) {
        if (dif[i] < 0 || now_sum <= 0) break;
        now_sum = max(now_sum-dif[i], 0LL);
        ++ans;
    }
    cout << ans << endl;
    return 0;
}
