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
#define N 1000001
#define fl 1.0000000000
//#define mod 998244353
#define cntbit(a) __builtin_popcountl(a)
#define ios ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
vector<int>adj[100005];
//int indeg[100005],lpath[100005];
int dp[2][100005];

void func(int v,int parent)
{

  int flg=0,t1=1,t2=1;
  for(auto x:adj[v])
  {
    if(x!=parent)
    {
        flg++;
        func(x,v);
    }
  }

for(auto x:adj[v])
{
    if(x!=parent)
    {
        t1*=(dp[1][x]);
        t1%=hell;
        t2*=(dp[0][x]+dp[1][x]);
        t2%=hell;
    }
}
dp[0][v]=t1;
dp[1][v]=t2;
return;
}

main()
{
  ios
int n,m,i;
int j;
int u,v,q;
int test=1;
//si(test);

while(test--)
{
  cin>>n;
  int x[n],y[n];
  for(i=0;i<n-1;i++)
    {
        cin>>x[i]>>y[i];
        adj[x[i]].push_back(y[i]);
        adj[y[i]].push_back(x[i]);

    }

    func(1,0);
    cout<<(dp[0][1]+dp[1][1])%hell;
}

}
