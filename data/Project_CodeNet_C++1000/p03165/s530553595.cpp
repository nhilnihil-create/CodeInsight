#include<bits/stdc++.h>
using namespace std;
#define lc "\n"
#define fast_io ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(0)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define int long long
#define c(a,n) for(int i = 0; i < n; i++) cin >> a[i];
#define ffor(n) for(int i = 0; i < n; i++)
 
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
    string s,t;
    cin>>s>>t;
    string res;
    int n=s.size();int m=t.size();
    vii dp(n+1,vi(m+1,0));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s[i-1]==t[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    int i=n;
    int j=m;
    while(i>0 && j>0)
    {
        
        if(s[i-1]==t[j-1])
        {
            res.push_back(s[i-1]);
            i--;j--;
            continue;
        }
         if(dp[i-1][j]>=dp[i][j-1])
        i--;
        else j--;
            
    }
    reverse(res.begin(),res.end());
    cout<<res;
    
    
    return 0;
}