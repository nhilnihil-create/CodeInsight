///Bismillahir Rahmanir Rahim
#include "bits/stdc++.h"

#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#pragma warning(disable:4786)
#pragma warning(disable:4996)

#define                           ll                          long long
#define                           int                         ll
#define                           fi                          first
#define                           si                          second
#define                           mp                          make_pair
#define                           pb                          push_back
#define                           pi                          pair<ll,ll>
#define                           clr(x)                      memset(x,0,sizeof(x));
#define                           f(i,l,r)                    for(int i=l;i<=r;i++)
#define                           rf(i,r,l)                   for(int i=r;i>=l;i--)
#define                           done(i)                     cout<<"done = "<<i<<endl;
#define                           show(x,y)                   cout<<x<<" : ";for(auto z:y)cout<<z<<" ";cout<<endl;
#define                           fast                        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

const ll inf=1e18;
const int mod=1e9+7;
const int M=10005;
int n,m,len;
int a[12];
int dp_len[M];
int cost[]={0,2,5,5,4,5,6,3,7,6};
int solve(int rem)
{
    if(rem<0)return -inf;
    if(rem==0)return 0;
    int &ret=dp_len[rem];
    if(ret!=(-1))return ret;
    ret=0;
    for(int i=1;i<=m;i++)
    {
        ret=max(ret,1+solve(rem-cost[a[i]]));
    }
    return ret;
}
vector<int>dp[M];
int yo(int baki,int pos)
{
    if(baki<0)return 0;
    if(pos>len)
    {
        if(baki==0)return 1;
        else return 0;
    }
    int &ret=dp[baki][pos];
    if(ret!=(-1))return ret;
    ret=0;
    for(int i=1;i<=m;i++)
    {
        int x=yo(baki-cost[a[i]],pos+1);
        if(x==1)ret=1;
    }
    return ret;
}
 main()

{
    fast
    cin>>n>>m;
    f(i,1,m)
    {
        cin>>a[i];
    }
    sort(a+1,a+m+1);
    reverse(a+1,a+m+1);
    memset(dp_len,-1,sizeof dp_len);
    len=solve(n);
    f(i,0,n+2)dp[i].assign(len+5,-1);
    string ses="";
    int has=n;
    for(int i=1;i<=len;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(yo(has-cost[a[j]],i+1))
            {
                has=has-cost[a[j]];
                ses+=(a[j]+'0');
                break;
            }
        }
    }
    cout<<ses<<endl;
    return 0;

}



































