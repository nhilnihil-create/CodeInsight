#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for (ll i = (a); i < (b); i++)
#define REP(i,n) rep(i,0,n)
int n,ans=0;

void dfs(ll x,bool a,bool b,bool c){
    if(x>n)return;
    if(a&b&c&1)ans++;
    dfs(x*10+3,1,b,c);
    dfs(x*10+5,a,1,c);
    dfs(x*10+7,a,b,1);
}

void solve() 
{
    cin>>n;dfs(0,0,0,0);cout<<ans<<endl;
}

int main()
{
    cin.tie(0);
	ios::sync_with_stdio(false);
    solve();
    return 0;
}