#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for (ll i = (a); i < (b); i++)
#define REP(i,n) rep(i,0,n)
#define mod (1000000007)
void solve() 
{
    ll n;cin>>n;
    string s;cin>>s;
    map<int,int>g;
    REP(i,n)g[s[i]]++;
    ll ans=1;
    REP(i,26)(ans*=g['a'+i]+1)%=mod;
    cout<<ans-1<<endl;
}

int main()
{
    cin.tie(0);
	ios::sync_with_stdio(false);
    solve();
    return 0;
}