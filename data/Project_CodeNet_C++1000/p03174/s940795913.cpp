#include <bits/stdc++.h>
using namespace std;

#define int         long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define f           first
#define s          second
#define sz(x)       (int)x.size()
#define rep(i,a,b)  for(int i=a;i<b;i++)
#define rep0(a,n)  for(int i=0;i<n;i++)cin>>a[i]
#define si(x)       cin>>x
#define sii(x,y)    cin>>x>>y
#define siii(x,y,z) cin>>x>>y>>z
#define ahell   998244353
#define hell 1000000007
#define N1 100001
#define fl 1.0000000000
//#define mod 998244353
#define cntbit(a) __builtin_popcountl(a)
#define ios ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
int dp[22][1<<21];
void func()
{
    ios
    int k,n,i,j,l;
    cin>>n;
    int a[n][n];
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            cin>>a[i][j];


    dp[0][0]=1;
    for(j=0;j<n;j++)
    {
        if(a[0][j])
        {
            dp[0][1<<j]=1;
        }
    }

    for(i=1;i<n;i++)
    {

        for(j=0;j<(1<<n);j++)
        {
            int mask=j;
            if(dp[i-1][j]==0)continue;

            for(k=0;k<n;k++)
            {
                if(a[i][k]==1&&(((mask>>k)&1)==0))
                {
                    dp[i][mask|(1<<k)]+=dp[i-1][mask];
                    dp[i][mask|(1<<k)]%=hell;
                }
            }
        }

    }

    cout<<dp[n-1][(1<<n)-1];
}
main()
{

int n,m,i;
int j;
int u,v,q;
int test=1;
//si(test);

while(test--)
{
string s;
int d;
func();
}

}
