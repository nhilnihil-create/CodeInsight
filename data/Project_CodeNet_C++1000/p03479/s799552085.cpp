#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);++i)
#define sayyes cout<<"Yes"<<endl;
#define sayno cout<<"No"<<endl;
#define vv(a,b) vector< vector<int> > v(a,vector<int>(b,0));
using namespace std;
typedef long long ll;
typedef pair<int,int>P;
const int mod =1e9+1;

int main()
{
    ll x,y;
    cin>>x>>y;
    ll ans=0;
    ll now=x;
    while(now<=y)
    {
        now*=2;
        ans++;
    }
    cout<<ans;
}