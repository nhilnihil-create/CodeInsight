#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ash[100001][4];
int f(ll a[],ll b[],ll c[],ll d, ll n,ll aa,ll bb,ll cc)
{
    ll hw=0,bug=0,sw=0;
    if(d==n)
    return 0;
    if(aa==0)
    {
 if(ash[d][0]!=-1)
    return ash[d][0];
    }
      if(bb==0)
    {
 if(ash[d][1]!=-1)
    return ash[d][1];
    }
      if(cc==0)
    {
 if(ash[d][2]!=-1)
    return ash[d][2];
    }
    if(aa==0)
    {
      //  aa=1,bb=0,cc=0;
        sw=a[d]+max(f(a,b,c,d+1,n,1,0,1),f(a,b,c,d+1,n,1,1,0));
    }
      if(bb==0)
    {
        bug=b[d]+max(f(a,b,c,d+1,n,0,1,1),f(a,b,c,d+1,n,1,1,0));
    }
      if(cc==0)
    {
        hw=c[d]+max(f(a,b,c,d+1,n,0,1,1),f(a,b,c,d+1,n,1,0,1));
    }
    //cout<<max(bug,max(hw,sw))<<" ";
    //ash[d]=max(bug,max(hw,sw));
    if(aa==0)
    return ash[d][0]=max(bug,max(hw,sw));
    if(bb==0)
    return ash[d][1]=max(bug,max(hw,sw));
    if(cc==0)
    return ash[d][2]=max(bug,max(hw,sw));
}
int main()
{
    memset(ash,-1,sizeof(ash));
    ll n;
    cin>>n;
    ll a[n],b[n],c[n];
    for(int i=0;i<n;i++)
    cin>>a[i]>>b[i]>>c[i];
    ll maxxfun=f(a,b,c,0,n,0,0,0);
    cout<<maxxfun<<" ";
    return 0;
}