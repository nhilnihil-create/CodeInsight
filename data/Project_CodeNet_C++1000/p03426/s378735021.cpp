///Bismillahir Rahmanir Rahim
#include "bits/stdc++.h"

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
int h,w,d,q;
int a[303][303];
vector<vector<int> >dp;
int vx[90012];
int vy[90012];
 main()

{
    fast
    cin>>h>>w>>d;
    dp.resize(d+1);
    f(i,1,h)
    {
        f(j,1,w)
        {
            cin>>a[i][j];
            vx[a[i][j]]=i;
            vy[a[i][j]]=j;
        }
    }
    for(int i=1;i<=d;i++)
    {
        int sum=0;
        dp[i].pb(sum);
        for(int j=i+d;j<=h*w;j=j+d)
        {
            int cx=vx[j];
            int cy=vy[j];
            int px=vx[j-d];
            int py=vy[j-d];
            int cost=abs(px-cx)+abs(py-cy);
            sum+=cost;
            dp[i].pb(sum);
        }
    }
    int q;
    cin>>q;
    while(q--)
    {
        int lft,rgt;
        cin>>lft>>rgt;
        if(lft==rgt)
        {
            cout<<"0"<<endl;
            continue;
        }
        int id=lft%d;
        if(id==0)id=d;
        int dan,bam;
        bam=(lft-1)/d;
        dan=(rgt-1)/d;
        int ses=dp[id][dan];
        ses-=dp[id][bam];
        cout<<ses<<endl;
    }
    return 0;
}
