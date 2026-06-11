#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define F first
#define S second
#define ii pair < int , int >
#define ever (;;)

const int N = 3010;

int n,m,dp[N][N];
char A[N],B[N];
string s,t,ans;

int main()
{
    scanf("%s%s",&A,&B);
    s = A;
    t = B;
    n = s.length();
    m = t.length();

    for(int i=n-1;i>=0;i--)
        for(int j=m-1;j>=0;j--)
            if( s[i] == t[j] )
                dp[i][j] = 1 + dp[i+1][j+1];
            else
                dp[i][j] = max( dp[i+1][j] , dp[i][j+1] );

    int p1 = 0,p2 = 0;

    while( p1 != n && p2 != m )
    {
        if( s[p1] == t[p2] )
        {
            ans += s[p1];
            p1++;
            p2++;
            continue;
        }

        if( dp[p1+1][p2] > dp[p1][p2+1] )
            p1++;
        else
            p2++;
    }

    printf("%s\n",ans.c_str());
}
