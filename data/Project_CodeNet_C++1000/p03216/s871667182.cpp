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
int n,q;
string s;
void solve()
{
    int k;
    cin>>k;
    int d,m,dm,ses;
    ses=d=m=dm=0;
    f(i,1,n)
    {
       if(i-k>=1)
       {
          if(s[i-k]=='D')dm-=m,d--;
          else if(s[i-k]=='M')m--;
       }
       if(s[i]=='D')d++;
       else if(s[i]=='M')m++,dm+=d;
       else if(s[i]=='C')ses+=dm;
    }
    cout<<ses<<endl;
}
 main()

{
    fast
    cin>>n>>s>>q;
    s="#"+s;
    while(q--)
    {
        solve();
    }
    return 0;

}



































