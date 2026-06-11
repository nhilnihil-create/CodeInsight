#include <bits/stdc++.h>
using namespace std;
 
using ll=long long;
 
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b)
#define pb push_back
#define eb emplace_back
#define a first
#define b second
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
const ll MOD = 998244353;


int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> vp;
    unordered_map<int, vector<int>> mp; 
    rep(i, m) {
        int p, y;
        cin >> p >> y;
        vp.emplace_back(p, y);
        mp[p].push_back(y);
    }
    for (auto& v : mp) sort(all(v.second));
    rep(i, m) {
        auto pi = vp[i];
        int p = pi.first; int y = pi.second;
        int idx = lower_bound(mp[p].begin(), mp[p].end(), y) - mp[p].begin();
        cout << setfill('0') << right << setw(6) << p;
        cout << setfill('0') << right << setw(6) << idx+1;
        cout << endl;
    }
    return 0;
}