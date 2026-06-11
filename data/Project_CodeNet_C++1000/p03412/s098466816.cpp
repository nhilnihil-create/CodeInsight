#include<bits/stdc++.h>
#define ll long long int
#define M 1000000007
#define mod 998244353
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define pi pair<ll,ll>
using namespace std;
const ll N=500010;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n;
    cin>>n;
    vector<ll> ar(n),br(n);
    for(ll i=0;i<n;++i){cin>>ar[i];}
    for(ll i=0;i<n;++i){cin>>br[i];}

    ll power[30];
    power[0]=1;
    for(ll i=1;i<30;++i){power[i]=2*power[i-1];}

    ll ans=0;
    for(ll i=0;i<29;++i)
    {
        ll t=power[i];
        vector<ll> ch(n);
        for(ll j=0;j<n;++j){
            ch[j]=br[j]%(2*t);
        }
        sort(ch.begin(),ch.end());
        ll count=0;
        for(ll j=0;j<n;++j){
            ll x=ar[j]%(2*t);
            count+=lower_bound(ch.begin(),ch.end(),2*t-x)-lower_bound(ch.begin(),ch.end(),t-x);
            count+=lower_bound(ch.begin(),ch.end(),4*t-x)-lower_bound(ch.begin(),ch.end(),3*t-x);
        }
        ans+=(count%2)*power[i];
    }
    cout<<ans;

    return (0);
}
