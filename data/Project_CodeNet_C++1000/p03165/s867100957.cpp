#include <bits/stdc++.h>
#define int long long
#define S second
#define F first
#define pb push_back
#define sz size()
using namespace std;
const int N=1e6+7;
const int mod=1e9+7;
int b[N],c[N],dp[3010][3010] ;
int n,x=1,ans,k,w,m ;
vector < int > vec ;
vector < int > pos ;
multiset < int > st ;
string s, t,f,ans2;

main()
{
    cin >> s >> t ;
    n=s.sz ;
    m=t.sz ;
    s='%'+s ;
    t='%'+t ;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            if (s[i]==t[j])
            dp[i][j]=dp[i-1][j-1]+1 ;
            else dp[i][j]=max(dp[i][j-1],dp[i-1][j]) ;

    while (n&&m)
    {
        if (s[n]==t[m])
            f+=s[n] , n-- , m-- ;
        else if (dp[n][m-1]>dp[n-1][m])
            m-- ;
        else n-- ;
    }
    reverse(f.begin(),f.end()) ;
    cout << f << endl ;
}

