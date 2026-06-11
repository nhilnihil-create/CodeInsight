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
    ll h;
    
    cin>>n>>h;
    vector<ll>a(n);
    vector<ll>b(n);
    rep(i,n)cin>>a[i]>>b[i];
    sort(a.begin(),a.end());
    sort(b.begin(),b.end(),greater<ll>());
    ll ans=0;
    for(auto v:b)
    {
        if(v>=a[n-1])
        {
            h-=v;
            ans++;
        }
        if(h<=0)
        {
            cout<<ans;
            return 0;
        }
    }
    ans+=h%a[n-1]==0?h/a[n-1]:h/a[n-1]+1;
    cout<<ans;

}
