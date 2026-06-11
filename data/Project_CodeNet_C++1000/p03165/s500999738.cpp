#include <bits/stdc++.h>
using namespace std;

/* macros */
#define inf 1e9
#define int long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector<int>
#define vc vector<char>
#define vb vector<bool>
#define vt vector
#define pb push_back
#define fi first
#define se second
#define pi pair<int,int>
#define tc int t;cin>>t;while (t--){solve();}
#define gtc int t;cin>>t;int TC=1;while (t--) {cout << "Case #" << TC << ": " << solve() << "\n";TC++;}
#define gvtc int t;cin>>t;int TC=1;while (t--) {cout << "Case #" << TC << ": "; vsolve(); TC++;}
#define notc solve();
#define newline cout << "\n";
#define mod 1000000007
#define ret return 0;
#define sz(x) (int)x.size();
#define rep(i,a,b) for(int i=a;i<b;i++)
#define srt(x) sort(x.begin(), x.end())
#define rsrt(x) sort(x.rbegin(), x.rend())

string s,t;
int m,n;

int dp[3001][3001];

int lcs(string X,string Y,int m,int n) {
    if (m == 0 || n == 0) {
        return 0;
    }
    
    if (dp[m][n] != -1) {
        return dp[m][n];
    }
    
    if (X[m-1] == Y[n-1]) {
        return lcs(X,Y,m-1,n-1) + 1;
    }
    
    int op1 = lcs(X,Y,m-1,n);
    int op2 = lcs(X,Y,m,n-1);
    
    int ans = max(op1, op2);
    
    return dp[m][n] = ans;
}

string lcsstr() {
    memset(dp, 0, sizeof dp);
    for (int i=1;i<=m;i++) {
        for (int j=1;j<=n;j++) {
            if (s[i-1] == t[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    int index = dp[m][n];
    string ans = string(index, 'a');
    int i=m,j=n;
    while (i>0 && j>0) {
        if (s[i-1] == t[j-1]) {
            ans[--index] = s[i-1];
            i--;
            j--;
        }else if (dp[i-1][j] > dp[i][j-1]) {
            i--;
        }else {
            j--;
        }
    }
    
    return ans;
}

void solve() {
    cin>>s>>t;
    m = sz(s);
    n = sz(t);
    memset(dp, -1, sizeof dp);
    string ans = lcsstr();
    cout << ans << "\n";
}

int32_t main(){
    fastio
    notc
    ret
}
