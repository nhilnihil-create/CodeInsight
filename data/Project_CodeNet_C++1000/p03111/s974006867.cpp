//Jai Bhole Ki
#include <bits/stdc++.h>
using namespace std;
#define fast static int fastline = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();
#define ll long long
#define LL unsigned ll
#define pb push_back
#define pi pair<ll,ll>
#define debug(x) cout<<x<<"\n";
#define debugg cout<<"debugged\n";
#define setpr(xval) cout<<fixed<<setprecision(12)<<xval<<endl;
#define minval -2e9
#define maxval 2e9
long double PI =3.14159265358979323846;
 
const ll M=1e9+7;
const ll inf=1e18;
const ll ms=2e5+5;
fast;
ll n,ans,ar[9],A,B,C;
void fun(ll i,pi a,pi b,pi c)
{
    if(i==n)
    {
        if(!a.second || !b.second || !c.second)
            return;
        ll temp=abs(a.first-A)+abs(b.first-B)+abs(c.first-C);
        if(a.second>1)
            temp+=(a.second-1)*10;
        if(b.second>1)
            temp+=(b.second-1)*10;
        if(c.second>1)
            temp+=(c.second-1)*10;
        ans=min(ans,temp);
        return;
    }
    fun(i+1,a,b,c);     fun(i+1,{a.first+ar[i],a.second+1},b,c);   fun(i+1,a,{b.first+ar[i],b.second+1},c);   fun(i+1,a,b,{c.first+ar[i],c.second+1});
}
void solve()
{
    cin>>n>>A>>B>>C;
    for(ll i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    ans=maxval;fun(0,{0,0},{0,0},{0,0});
    cout<<ans<<endl;
}

int main()
{
 // freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    //int t;cin>>t;while(t--)
    {
        solve();
    }
    return 0;
}