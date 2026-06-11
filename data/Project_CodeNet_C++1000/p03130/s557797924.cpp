#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for (ll i = (a); i < (b); i++)
#define REP(i,n) rep(i,0,n)

void solve() 
{
    vector<int>g(4,0);
    REP(i,6){
        int a;cin>>a;a--;
        g[a]++;
    }
    REP(i,4){
        if(g[i]==0||g[i]==3){cout<<"NO"<<endl;return;}
    }cout<<"YES"<<endl;
}

int main()
{
    cin.tie(0);
	ios::sync_with_stdio(false);
    solve();
    return 0;
}