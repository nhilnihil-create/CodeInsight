#include <bits/stdc++.h>
#define int long long
#define S second
#define F first
#define pb push_back
#define sz size()
using namespace std;
const int N=1e6+7;
const int mod=1e9+7;
int b[N],c[N],dp[2000][2000] ;
int n,x=1,ans,k,w,m ;
char a[2000][2000] ;
vector < int > vec ;
vector < int > pos ;
multiset < int > st ;
main()
{
    cin >> n >> m ;
    dp[1][1]=1 ;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
        {
            cin >> a[i][j] ;
            if (a[i][j]!='#')
                dp[i][j]+=dp[i-1][j]+dp[i][j-1] ;
            dp[i][j]%=mod ;
        }
    cout << dp[n][m] << endl;
}
