#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for (ll i = (a); i < (b); i++)
#define REP(i,n) rep(i,0,n)

void solve() 
{
    int n;string s;cin>>n>>s;
    int cntw=0,cntb=0;
    int ans=999999999;
    REP(i,n){
        if(s[i]=='.')cntw++;
    }
    REP(i,n){
        ans=min(cntw+cntb,ans);
        if(s[i]=='.'&&cntw>0)cntw--;
        if(s[i]=='#')cntb++;
    }ans=min(cntw+cntb,ans);
    cout<<ans<<endl;
    
}

int main()
{
    cin.tie(0);
	ios::sync_with_stdio(false);
    solve();
    return 0;
}