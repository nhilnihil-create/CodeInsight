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
    int n;
    cin>>n;
    vi a(n);
    c(a,n);
    vii dp(n,vi(n,LLONG_MAX));
    vi pre(n+1,0);
    for(int i=1;i<=n;i++)pre[i]=a[i-1]+pre[i-1];
    for(int i=0;i<n;i++)dp[i][i]=0;
    for(int i=0;i<n-1;i++)
    dp[i][i+1]=a[i]+a[i+1];

    for(int size=3;size<=n;size++)
    {
        for(int i=0;i<=n-size;i++)
        {
            for(int l=i;l<i+size-1;l++)
            dp[i][i+size-1]=min(dp[i][i+size-1],pre[i+size]-pre[i]+dp[i][l]+dp[l+1][i+size-1]);
        }
    }
    cout<<dp[0][n-1];
    return 0;
}