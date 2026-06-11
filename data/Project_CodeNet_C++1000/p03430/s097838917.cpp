#include <bits/stdc++.h>
using namespace std;
#define finish(x) return cout << x << endl, 0
#define ll long long

const int N = 301;

int n, k, dp[N][N][N];
string s;

int solve(int l, int r, int k){
    if(r < l) return 0;
    if(l == r) return 1;
    int &ret = dp[l][r][k];
    if(ret != -1) return ret;
    ret = max(solve(l + 1, r, k), solve(l, r - 1, k));
    if(s[l] == s[r]) ret = max(ret, solve(l + 1, r - 1, k) + 2);
    else if(k > 0) ret = max(ret, solve(l + 1, r - 1, k - 1) + 2);
    return ret;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(dp, -1, sizeof dp);
    cin >> s >> k;
    n = s.size();
    cout << solve(0, n - 1, k) << endl;
}
