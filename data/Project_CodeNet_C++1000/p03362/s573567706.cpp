///Bismillahir Rahmanir Rahim
#include "bits/stdc++.h"

#define                           ll                          long long
#define                           int                         ll
#define                           fi                          first
#define                           si                          second
#define                           mp                          make_pair
#define                           pb                          push_back
#define                           pi                          pair<ll,ll>
#define                           node(a,b,c)                 mp(mp(a,b),c)
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
vector<int>prime;
bool sv[M+10];
void sieve()
{
     int i,j;
     for(i=4;i<=M;i=i+2)
    {
           sv[i]=1;
    }
    for(i=3;i*i<=M;i=i+2)
    {
        if(sv[i]==0)
        {
              for(j=i*i;j<=M;j=j+2*i)
              {
                  sv[j]=1;
              }
        }
    }
    for(i=3;i<M;i=i+2)
    {
        if(sv[i]==0 && i%5==1)
        {
            prime.push_back(i);
        }
    }
}
 main()

{
    fast
    int n;
    cin>>n;
    sieve();
    for(int i=0;i<n;i++)
    {
        cout<<prime[i]<<" ";
    }
    cout<<endl;
    return 0;

}



































