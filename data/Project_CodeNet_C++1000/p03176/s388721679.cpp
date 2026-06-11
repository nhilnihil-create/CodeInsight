#include <bits/stdc++.h>
#include<math.h>
using namespace std;
#define int long long int
#define endl "\n"
#define PI 3.14159265
const int mod=1e9+7;
//const int mod=1e9+7;
const int INF =LONG_LONG_MAX;
inline int gcd(int a,int b){if(a==0) return b;return gcd(b%a,a);}
inline int pow(int a,int n,int mod){if(n==0)return 1;int p=pow(a,n/2,mod);p=(p%mod*p%mod)%mod;if(n%2) return (p%mod*a%mod)%mod;else return p;}
const int N = (int)2e5 + 10;
int tree[4 * N];
int dp[N];
int h[N], val[N];
int n;
void build(int node,int start,int end,int tree[],int a[])
{
    if(start==end)
     { tree[node]=a[start]; return;}
    int mid=(start+end)/2;
    build(2*node,start,mid,tree,a);
    build(2*node+1,mid+1,end,tree,a);
    tree[node]=min(tree[2*node],tree[2*node+1]);
}

void update(int node,int start,int end,int idx,int val)
{
    if(start==end)
   {
       //a[idx]=val;
       tree[node]=val;
    }
   else
 {
    int mid=(start+end)/2;
   if(idx>=start&&idx<=mid)
     update(2*node+1,start,mid,idx,val);
   else
      update(2*node+2,mid+1,end,idx,val);
    tree[node]=max(tree[2*node+1],tree[2*node+2]);
   }
}

int query(int node,int start,int end,int l,int r)
{
    if(l>end||start>r)
      return -1;
   if(l<=start&&r>=end)
      return tree[node];
   int p1,p2;
    int mid=(start+end)/2;

   p1=query(2*node+1,start,mid,l,r);
   p2=query(2*node+2,mid+1,end,l,r);
    return max(p1,p2);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=0;i<=4*n;i++)tree[i]=0;
    for(int i=1;i<=n;i++)
        cin>>h[i];
    for(int i=1;i<=n;i++)
        {cin>>val[i];}
    for(int i=1;i<=n;i++)dp[h[i]]=val[i];
    dp[0]=0;

    for(int i=1;i<=n;i++)
    {
        int d=query(0,1,n,1,h[i]-1);
        dp[h[i]]=max(dp[h[i]],d+val[i]);
        update(0,1,n,h[i],dp[h[i]]);
    }
    int max1=-1;
    for(int i=1;i<=n;i++)
        max1=max(max1,dp[i]);
    cout<<max1<<endl;

    return 0;
}
