//----------------------------------------------------------------------
#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
//----------------------------------------------------------------------

using namespace std;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;

int main(void) {
    int n, k;
    cin >> n  >> k;
    vector<int> x(n);
    rep(i, n) cin >> x[i];

    ll ans = 1e15;
    rep(i,n-k+1) {
        ll left = x[i];
        ll right = x[i+k-1];
        ll tmp = min(abs(left) + abs(right-left), abs(right) + abs(right - left));
        ans = min(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}
