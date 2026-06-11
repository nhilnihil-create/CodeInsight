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
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    map<int, int> mp;
    rep(i, n) {
        mp[a[i]] ++;
    }

    int num = mp.size();
    if(num < k) {
        cout << 0 <<  endl;
        return 0;
    }
    vector<int> ans;
    for(auto v : mp) {
        ans.push_back(v.second);
    }
    int delnum = num - k;
    sort(ans.begin(), ans.end());
    ll anss = 0;
    rep(i, delnum) {
        anss += ans[i];
    }
    cout << anss << endl;
    return 0;
}
