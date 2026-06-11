#include <bits/stdc++.h>   


#define for0(i, n) for (long long  i = 0; i < n; i++) 
#define for1(i, n) for (long long  i = 1; i <= n; i++) 
#define forc(i, l, r) for (long long  i = l; i <= r; ++i) 
#define forr0(i, n) for (long long  i = n - 1; i >= 0; i--) 
#define forr1(i, n) for (long long  i = n; i >= 1; i--) 


#define pb push_back
#define fi first
#define se second


#define all(x) (x).begin(), (x).end() 
#define rall(x) (x).rbegin, (x).rend() 

using namespace std;


typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef long long int lli;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef double ld;

const ll N = 1e5 + 5;
const ll mod = 1e9 + 7;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    {
        ll i,j,k,n,m,cnt,x,y;
        string a,b;
        cin>>a>>b;
        n = a.length();
        m = b.length();
        ll dp[n+1][m+1];
        for(i=0;i<=n;i++)
        {
            for(j=0;j<=m;j++)
            {
                if(i==0 || j==0)
                {
                    dp[i][j]=0;
                }
                else if(a[i-1]==b[j-1])
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        cnt = dp[n][m];
        char lcs[cnt+1];
        lcs[cnt]='\0';
        i=n,j=m;
        while(i>0 && j>0)
        {
            if(a[i-1]==b[j-1])
            {
                lcs[cnt-1]=a[i-1];
                i--,j--,cnt--;
            }
            else if(dp[i-1][j]>dp[i][j-1]) i--;
            else j--;
        }
        cout<<lcs<<endl;
    }
    
    return 0;
}