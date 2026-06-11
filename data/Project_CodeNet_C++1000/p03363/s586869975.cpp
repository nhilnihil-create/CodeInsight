//----------------------------------------------------------------------
#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
//----------------------------------------------------------------------

using namespace std;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;

int main(void) {
    int n;
    cin >> n;
    vector<int> a(n);
    REP(i, n) cin >> a[i];
    vector<ll> s(n+1,0);
    REP(i, n) s[i+1] = s[i] + a[i];
    map<ll, ll> nums;
    REP(i, n+1) nums[s[i]]++;

    ll res = 0;
    for(auto it : nums) {
        ll num = it.second;
        res += (num) * (num-1) / 2;
    }
    cout << res << endl;

    return 0;
}