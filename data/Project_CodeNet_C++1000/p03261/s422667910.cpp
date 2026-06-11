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
ll n,m,x,y,ans;
void solve()
{
    cin>>n;
    map<string,bool>mp;
    vector<string> s(n);
    for(int i=0;i<n;i++)
        cin>>s[i];
    mp[s[0]]=1;
    for(int i=1;i<n;i++)
    {
        if((s[i][0]!=s[i-1][s[i-1].size()-1])||mp[s[i]])
            {cout<<"No"<<endl;return;}
        mp[s[i]]=1;
    }
    
    cout<<"Yes";
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
