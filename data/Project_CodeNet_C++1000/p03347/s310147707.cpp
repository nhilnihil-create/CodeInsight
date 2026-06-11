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
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    if (a[0] != 0) {
        cout << -1 << endl;
        return 0;
    }
    ll ans = 0;
    ll sum = 0;
    rep(i, n-1) {
        if (a[i] >= a[i+1]) {
            ans += sum;
            sum = a[i+1];
        }
        else if (a[i+1] > sum + 1) {
            cout << -1 << endl;
            return 0;
        }
        else {
            sum += (a[i+1] - a[i]);
        }
    }
    ans += sum;
    cout << ans << endl;
    return 0;
}
