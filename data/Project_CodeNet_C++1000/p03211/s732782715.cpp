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
ll ans,temp;
void solve()
{
    string s;cin>>s;
    for(int i=0;i<3;i++)
    {
        temp*=10;
        temp+=s[i]-'0';
    }ans=abs(753ll-temp);
    for(int i=3;i<s.size();i++)
    {
        temp=(temp%100)*10+s[i]-'0';
        
        ans=min(abs(753ll-temp),ans);
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