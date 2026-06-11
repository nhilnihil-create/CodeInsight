#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int, int>
#define vi vector<int>
#define pb emplace_back
#define sz(x) (int)x.size()
#define all(v) v.begin(), v.end()
#define x first
#define y second
#define rep(i, j, k) for(i=j; i<k; i++)
#define sep(i, j, k) for(i=j; i>k; i--)
const int N = 2e4+5, inf = 1e9+7;
int n, k, i, j;
struct nd{int w, s, v;};
nd v[N];
int dp[N];
bool cmp(nd&a, nd&b){ return a.w+a.s<b.w+b.s; }
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int i, j, a, b, ans = 0;
    cin>>n;
    rep(i, 1, n+1) cin>>v[i].w>>v[i].s>>v[i].v;
    sort(v+1, v+n+1, cmp);
    rep(i, 1, n+1)
        for(int w = v[i].s; w >= 0; w--)
            dp[w+v[i].w] = max(dp[w+v[i].w], dp[w]+v[i].v);
    cout<<*max_element(dp, dp+N);
}