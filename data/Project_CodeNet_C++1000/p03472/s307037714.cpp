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
    ll h;
    cin >> h;
    vector<ll> a(n), b(n);
    ll amax = 0;
    vector<ll> baccum(n+1, 0);
    rep(i, n) {
        cin >> a[i] >> b[i];
        amax = max(amax, a[i]);
    }
    sort(b.rbegin(), b.rend());
    ll cnt = 0;
    rep(i, n) {
        if (h <= 0) {
            cout << cnt << endl;
            return 0;
        }
        if (b[i] <= amax) {
            cnt += (h+amax-1) / amax;
            cout << cnt << endl;
            return 0;
        }
        h -= b[i];
        ++cnt;
    }
    cout << cnt + (h+amax-1)/amax << endl;
    return 0;
}
