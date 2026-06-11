#include<bits/stdc++.h>
using namespace std;
#define lc "\n"
#define fast_io ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(0)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define int long long
#define c(a,n) for(size_t i = 0; i < n; i++) cin >> a[i];
#define ffor(n) for(size_t i = 0; i < n; i++)
#define asort(a) sort(a.begin(), a.end())
#define rsort(a) sort(a.begin(), a.end(), greater<int>())

typedef vector<int> vi;
typedef vector<float> vf;
typedef vector<vi> vii;
typedef vector<string> vs;
typedef vector<long long> vll;
typedef map<string,int> msi;
typedef map<int,int> mii;
typedef unordered_map<string,int> umsi;


int32_t main()
{
    fast_io;
    string s, t;
    cin >> s >> t;
    int lens = s.length(), lent = t.length();    
    vii dp(lent+1, vi(lens+1));
    for(int i = 1; i <= lent; i++)
    {
        for(int j = 1; j <= lens; j++)
        {
            if(s[j-1] == t[i-1])
                dp[i][j] = dp[i-1][j-1]+1;
            else
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
            
        }
    }
    string ans = "";
    for(int r = lent, c = lens; r > 0 && c > 0;)
    {
        if(dp[r][c] == dp[r][c-1])
            c--;
        else if(dp[r][c] == dp[r-1][c])
            r--;
        else
        {
            ans += t[r-1];
            r--;
            c--;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
    return 0;
}   