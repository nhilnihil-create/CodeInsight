//Jai Bhole Ki
#include <bits/stdc++.h>
using namespace std;
#define fast static int fastline = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();
#define ll long long
#define LL unsigned ll
#define pb push_back
#define pi pair<ll,ll>
#define debug(x) cout<<x<<"\n";
#define debug cout<<"debugged\n";
#define minval -2e9
#define maxval 2e9
long double PI =3.14159265358979323846;
 
const ll M=1e9+7;
const ll inf=1e18;
const ll ms=1e7+2;
fast;
ll ans;
ll a,b,c;
void solve()
{
   cin>>a>>b>>c;
   for(int i=0;i<10;i++)
    {
        c=c*a-b;
        cout<<c<<endl;
    }
}

int main()
{
 // freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
   // int t;cin>>t;while(t--)
    {
        solve();
    }
    return 0;
}
