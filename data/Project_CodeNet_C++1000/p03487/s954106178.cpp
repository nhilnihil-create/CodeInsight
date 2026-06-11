//----------------------------------------------------------------------
#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
//----------------------------------------------------------------------

using namespace std;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;

int main(void) {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    map<int, int> mp;

    rep(i, n) {
        mp[a[i]] ++;
    }

    ll ans = 0;
    for(auto v : mp) {
        if(v.second > v.first) {
            ans += v.second - v.first;
        } else if(v.second != v.first) {
            ans += v.second;
        }
    }
    cout << ans << endl;
    return 0;
}
