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
void solve()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a<b || d<b)
    {
        cout<<"No"<<endl;
        return ;
    }
    if(c>=b-1)
    {
        cout<<"Yes"<<endl;return ;
    }
    int g=__gcd(b,d);
    int k=(b-(a%b)+g-1)/g;k--;
    int ses=(a%b)+k*g;
    if(ses>c)
    {
        cout<<"No"<<endl;return ;
    }
    cout<<"Yes"<<endl;
}
 main()

{
    fast
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;

}



































