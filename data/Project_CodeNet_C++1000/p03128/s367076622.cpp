#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<deque>
#include<map>
#include<bitset>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0;i < (n);i++)
#define repr(i, n) for(int i = (n);i >= 0;i--)
#define repf(i, m, n) for(int i = (m);i < (n);i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1;} return 0;}
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1;} return 0;}
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
//////////////////////////////////////////////////

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    rep(i, m) cin >> a[i];
    map<int, int> mp;
    mp[1] = 2; mp[2] = 5; mp[3] = 5;
    mp[4] = 4; mp[5] = 5; mp[6] = 6;
    mp[7] = 3; mp[8] = 7; mp[9] = 6;

    vector<string> dp(10010, "");
    vector<bool> ok(10010, false);

    ok[0] = true;
    rep(i,n) {
        if (!ok[i]) continue;
        for (int v : a) {
            if (dp[i+mp[v]].size() < dp[i].size()+1 || dp[i+mp[v]] < dp[i]+to_string(v)) {
                dp[i+mp[v]] = dp[i]+to_string(v);
                ok[i+mp[v]] = true;
            }
        }
    }
    cout << dp[n] << endl;
    return 0;
}
