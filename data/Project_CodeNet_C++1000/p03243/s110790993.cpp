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
ll ans,n,t;
void solve()
{
    cin>>n;
    for(int i=n;i<=999;i++)
    {
        ll nn=i;bool flag=1;
        ll dig=nn%10;
        nn/=10;
        while(nn)
        {
            if(dig!=nn%10)
                {flag=0;break;}
                nn/=10;
        }
        if(flag)
            {cout<<i<<endl;return;}
    }
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