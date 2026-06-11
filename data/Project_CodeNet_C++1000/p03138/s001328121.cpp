///Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>

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
const int M=100005;
bitset<46>a[M],kk;
int n,k,x,ses=0;
int c1[46],c2[46];
int dp[46][2];
int Magic(int pos,int is_sml)
{
    if(pos<0)return 0;
    int &ret=dp[pos][is_sml];
    if(ret!=(-1))return ret;
    ret=0;
    if(is_sml)
    {
        int c=max(c1[pos],c2[pos]);
        int cost=(c*(1LL<<pos));
        ret=cost+Magic(pos-1,is_sml);
    }
    else
    {
        if(kk[pos]==1)
        {
            int cost=c1[pos]*(1LL<<pos);
            ret=max(ret,cost+Magic(pos-1,1));
            cost=c2[pos]*(1LL<<pos);
            ret=max(ret,cost+Magic(pos-1,is_sml));
        }
        else
        {
            int c=c1[pos];
            int cost=c*(1LL<<pos);
            ret=cost+Magic(pos-1,is_sml);
        }
    }
    return ret;
}
 main()

{
    fast
    memset(dp,-1,sizeof dp);
    cin>>n>>k;
    f(i,1,n)
    {
        cin>>x;
        a[i]=x;
        f(j,0,45)
        {
            if(a[i][j])c1[j]++;
            else c2[j]++;
        }
    }
    kk=k;
    int mx_k=-1;
    f(j,0,45)
    {
        if(kk[j])mx_k=j;
    }
    rf(j,45,mx_k+1)
    {
        ses+=(c1[j]*(1LL<<j));
    }
    ses+=Magic(mx_k,0);
    cout<<ses<<endl;
    return 0;

}



































