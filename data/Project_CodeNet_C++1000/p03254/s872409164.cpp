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
    ll x;
    cin >> x;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    sort(a.begin(), a.end());
    int ans = 0;
    while(1) {
        //cout << x << endl;
        if (x < a[ans] || ans == n) break;
        if (ans == n-1 && x != a[ans]) break;
        x -= a[ans];
        //cout << "test" << endl;
        ++ans;
    }
    cout << ans << endl;
    return 0;
}
