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
ll ans,n,p;
void solve()
{
    cin>>p>>n;
    vector<vector<ll>> pre(p+1);
    vector<pi> vc(n);
    for(int i=0;i<n;i++)
    {
        cin>>vc[i].first>>vc[i].second;
        pre[vc[i].first].pb(vc[i].second);
    }
    for(int i=1;i<=p;i++)
    {
        sort(pre[i].begin(),pre[i].end());
    }
    for(int i=0;i<n;i++)
    {
        //cout<<vc[i].first<<" "<<vc[i].second<<endl;
        ll temp=lower_bound(pre[vc[i].first].begin(),pre[vc[i].first].end(),vc[i].second)-pre[vc[i].first].begin();
        temp++;
        //cout<<temp<<endl;
        string s="000000",ss="000000";
        //cout<<ss<<s<<endl;
        ll k=5;
        while(temp)
        {
            s[k--]=char(temp%10+'0');temp/=10;
        }
        temp=vc[i].first;k=5;
        while(temp)
        {
            ss[k--]=char(temp%10+'0');temp/=10;
        }
        cout<<ss<<s<<endl;
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