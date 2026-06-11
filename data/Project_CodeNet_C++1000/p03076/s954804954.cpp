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
const ll ms=2e5+5;
fast;
ll n,m,c,ans;
bool compare(ll &a,ll &b)
{
    return ((a-1)%10+1)>((b-1)%10+1);
}
void solve()
{
    vector<ll> ar(5);
   for(int i=0;i<5;i++)
    cin>>ar[i];
   sort(ar.begin(),ar.end(),compare);
   for(int i=0;i<5;i++)
   {
       ans=ceil(ans*1.0/10)*10+ar[i];
   }
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
