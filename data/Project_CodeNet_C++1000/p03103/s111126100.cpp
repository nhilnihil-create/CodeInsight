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
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main(){
    int n, m;
    cin >> n >> m;
    vector<pair<ll, int>> ab(n);
    rep(i, n) {
        ll a;
        int b;
        cin >> a >> b;
        ab[i] = {a, b};
    }
    sort(ab.begin(), ab.end());
    ll ans = 0;
    int cnt = 0;
    rep(i, n) {
        if ( cnt >= m ) break;
        if ( cnt + ab[i].second >= m ) {
            ans += ab[i].first * ( m - cnt );
            break;
        }
        else {
            ans += ab[i].first * ab[i].second;
            cnt += ab[i].second;
        }
    }
    cout << ans << endl;
    return 0;
}
