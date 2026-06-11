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
#define minval -2e9
#define maxval 2e9
long double PI =3.14159265358979323846;
 
const ll M=1e9+7;
const ll inf=1e18;
const ll ms=2e5+5;
fast;
ll ans,n,i;
void fun(ll num,ll t,ll f,ll s)
{
    //cout<<num<<" "<<ans<<endl;
    if(num>n)
        return ;
       if(t&&f&&s)
            ans++;
   i--;
   fun(num*10+3,t+1,f,s);fun(num*10+5,t,f+1,s);fun(num*10+7,t,f,s+1);
   i++;
}
void solve()
{
    cin>>n;
    if(n<357)
    {debug(ans);return;}
    ll nn=n;
    while(nn)
    {
        nn/=10;
        i++;
    }
    fun(0,0,0,0);
    debug(ans);return;
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