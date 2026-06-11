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
int rong[102][102];
 main()

{
    fast
    int a,b;
    cin>>a>>b;
    int cnt=0;
    f(i,1,50)
    {
        f(j,1,100)
        {
            if(i%2==1 && j%2==1)
            {
                if(cnt<a-1)
                {
                    cnt++;
                    rong[i][j]=1;
                }
            }
        }
    }
    f(i,51,100)
    {
        f(j,1,100)
        {
            rong[i][j]=1;
        }
    }
    cnt=0;
     f(i,51,100)
    {
        f(j,1,100)
        {
            if(i%2==0 && j%2==0)
            {
                if(cnt<b-1)
                {
                    cnt++;
                    rong[i][j]=0;
                }
            }
        }
    }
    cout<<"100 100"<<endl;
    f(i,1,100)
    {
        f(j,1,100)
        {
            if(rong[i][j]==0)
            {
                cout<<"#";
            }
            else cout<<".";
        }
        cout<<"\n";
    }
    return 0;

}



































