//----------------------------------------------------------------------
#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
//----------------------------------------------------------------------

using namespace std;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;

int main(void) {
    ll x, y;
    cin >> x >> y;
    ll ans = 0;
    ll value = x;

    while(value <= y) {
        value *= 2;
        ans++;
    }
    cout << ans << endl;
    return 0;
}
