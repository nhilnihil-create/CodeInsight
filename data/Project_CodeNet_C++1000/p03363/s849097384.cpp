#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);++i)
#define sayyes cout<<"Yes"<<endl;
#define sayno cout<<"No"<<endl;
using namespace std;
typedef long long ll;
const double PI=acos(-1);
typedef pair<int,int>P;
const int mod =1e9+7;

int main()
{
    int n;
    cin>>n;
    vector<ll> a(n,0);
    ll total=0;
    rep(i,n)
    {
        ll t;
        cin>>t;
        total+=t;
        a[i]=total;
    }
    map<ll,ll> cc;
    rep(i,n)
    {
        cc[a[i]]++;
    }
    ll ans=0;
    for(auto v:cc)
    {
        if(v.first==0)
        {
            ans+=v.second;
        }
        ans+=(v.second)*(v.second-1)/2;
    }
    cout<<ans;

}
