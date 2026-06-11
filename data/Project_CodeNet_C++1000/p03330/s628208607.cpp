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
int n,c;
int d[32][32];
int cr[505][505];
vector<int>vec[3];
int cost[31][3];
 main()

{
    fast
    cin>>n>>c;
    f(i,1,c)f(j,1,c)cin>>d[i][j];
    f(i,1,n)f(j,1,n)cin>>cr[i][j],vec[(i+j)%3].pb(cr[i][j]);
    f(i,1,c)
    {
        f(j,0,2)
        {
            int sum=0;
            for(auto x:vec[j])
            {
                if(x==i)continue;
                else sum+=d[x][i];
            }
            cost[i][j]=sum;
        }
    }
    int ses=inf;
    f(i,1,c)f(j,1,c)f(k,1,c)
    {
        if(i==j || i==k || j==k)continue;
        int tmp=cost[i][0]+cost[j][1]+cost[k][2];
        ses=min(ses,tmp);
    }
    cout<<ses<<endl;
    return 0;

}



































