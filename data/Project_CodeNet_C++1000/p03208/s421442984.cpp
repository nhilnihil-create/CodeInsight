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

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main(){
    int n, k;
    cin >> n >> k;
    vector<ll> h(n);
    rep(i, n) cin >> h[i];
    sort(h.begin(), h.end());
    ll ans = 1e18;
    rep(i, n - k + 1) {
        ans = min(ans, h[k+i-1]-h[i]);
    }
    cout << ans << endl;
    return 0;
}
