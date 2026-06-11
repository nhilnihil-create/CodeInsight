#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long int
#define endl "\n"     
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

const int N=1e3+5;
const int M=2e4+2;

int n;
int cache[N][M];

struct data
{
     int w,s,v;
};
data a[N];

bool cmp(data x,data y)
{
     return (x.w+x.s<y.w+y.s);
}

int dp(int pos,int weight)
{
     if(pos==n+1)
          return 0;
     int &ans=cache[pos][weight];
     if(ans!=-1)
          return ans;
     ans=dp(pos+1,weight);
     if(a[pos].s>=weight)
          ans=max(ans,a[pos].v+dp(pos+1,weight+a[pos].w));
     return ans;     
}

int32_t main()
{
     IOS;
     
     memset(cache,-1,sizeof cache);
     cin>>n;
     for(int i=1;i<=n;i++)
          cin>>a[i].w>>a[i].s>>a[i].v;
     sort(a+1,a+1+n,cmp);
     cout<<dp(1,0);
     return 0;
}
