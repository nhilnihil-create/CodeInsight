#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int>
#define X first
#define Y second 

int main () {
    int n;
    cin >> n;
    int input[n][n];
    fop (i,0,n) fop (j,0,n) cin >> input[i][j];
    lli sum[1 << n], dp[1 << n];
    dp[0] = sum[0] = 0;
    fop (s,1,1 << n) {
        vector <int> v;
        dp[s] = sum[s] = 0;
        fop (i,0,n) if (s & (1 << i)) v.pb(i);
        fop (i,0,v.size()) {
            fop (j,i+1,v.size()) {
                sum[s] += input[v[i]][v[j]];
            }
        }
        dp[s] = sum[s];
    }
    fop (s,0,1 << n) {
        int now = s;
        while (now > 0) {
            dp[s] = max(dp[s], dp[s ^ now] + sum[now]);
            now = (now - 1) & s;
        }
    }
    cout << dp[(1 << n) - 1] << endl;
}