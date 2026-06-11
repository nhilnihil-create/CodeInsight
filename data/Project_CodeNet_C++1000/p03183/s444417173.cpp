#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

#define p_ary(ary,a,b,i) do { cout << "["; for (int (i) = (a);(i) < (b);++(i)) cout << ary[(i)] << ((b)-1 == (i) ? "" : ", "); cout << "]\n"; } while(0)
#define p_map(map,it) do {cout << "{";for (auto (it) = map.begin();;++(it)) {if ((it) == map.end()) {cout << "}\n";break;}else cout << "" << (it)->first << "=>" << (it)->second << ", ";}}while(0)

struct block {
    int w,s,v;
    bool operator<(const block& a) const {
        return w+s < a.s+a.w;
    }
};

int main() {
    int n;
    cin >> n;
    vector<block> a(n);
    for (int i = 0;i < n;++i) cin >> a[i].w >> a[i].s >> a[i].v;
    sort(a.begin(),a.end());
    vector<vector<ll>> dp(n+1,vector<ll>(20010,0));
    for (int i = 0;i < n;++i) {
        dp[i+1] = dp[i];
        for (int j = 0;j <= a[i].s;++j) dp[i+1][j+a[i].w] = max(dp[i+1][j+a[i].w],dp[i][j]+a[i].v);
    }
    ll ans = 0;
    for (int i = 0;i < 20010;++i) ans = max(ans,dp[n][i]);
    cout << ans << endl;
    return 0;
}