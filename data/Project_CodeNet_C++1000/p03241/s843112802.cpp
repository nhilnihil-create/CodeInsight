#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);++i)
#define sayyes cout<<"Yes"<<endl;
#define sayno cout<<"No"<<endl;
using namespace std;
typedef long long ll;
const double PI=acos(-1);
typedef pair<int,int>P;
const int mod =1e9+7;


vector<ll> divisor(ll n)
{
    vector<ll> res;
    for(ll i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            res.push_back(i);
            if(i!=n/i)res.push_back(n/i);

        }
    }
    return res;
}
int main()
{
    int n;
    ll m;
    cin>>n>>m;
    auto div=divisor(m);
    sort(div.begin(),div.end());
    ll ans=upper_bound(div.begin(),div.end(),m/n)-div.begin();
    cout<<div[ans-1];

    

}
