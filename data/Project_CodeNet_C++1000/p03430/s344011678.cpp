#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 1e5 + 2, inf = 1e18;

string s, t;
int n, k;
int dp[302][302][302];

int go(int l, int r, int rem){
    if(rem < 0)
        return -inf;
    if(l >= r)
        return l == r;

    int &ans = dp[l][r][rem];
    if(~ans) return ans;

    ans = 0;
    if(s[l] == s[r])
        ans = max(ans, 2 + go(l + 1, r - 1, rem));
    ans = max(ans, 2 + go(l + 1, r - 1, rem - 1));
    ans = max({ans, go(l + 1, r, rem), go(l, r - 1, rem)});
    return ans;

}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  

    memset(dp, -1, sizeof(dp));
    cin >> s >> k;
    n = sz(s);
    cout << go(0,n-1,k);
}