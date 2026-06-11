#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
using namespace std;
const int maxn = 1000005;
const int mod = 998244353;
vector<int>tar;
int cnt[40][2];
ll dp[40][2];
ll dfs(int pos, int lim) {
    if (pos == -1) return 0;
    if (~dp[pos][lim]) return dp[pos][lim];
    int ub = lim ? tar[pos] : 1;
    ll mx = 0;
    for (int i = 0 ; i <= ub ; i++) {
        mx = max(mx, cnt[pos][i^1] * (1LL<<pos) + dfs(pos-1,lim && (i==ub)));
    }
    return dp[pos][lim] = mx;
}
int main(){
    //cout << (1LL<<40) << endl;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, k;
    cin >> n >> k;
    vector<ll>v;
    f (n) {
        ll x;
        cin >> x;
        v.pb(x);
    }
    tar.resize(40);
    for (int i = 0 ; i < 40 ; i++) {
        tar[i] = k % 2;
        k /= 2;
    }
    for (int i = 39 ; i >= 0 ; i--) {
        for (auto &j : v) {
            if (j & (1LL<<i)) {
                cnt[i][1]++;
            }
            else {
                cnt[i][0]++;
            }
        }
    }
    memset(dp, -1, sizeof(dp));
    cout << dfs(39,1) << '\n';
}