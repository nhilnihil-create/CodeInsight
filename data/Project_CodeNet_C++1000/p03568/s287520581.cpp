#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(long long i = 0; i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1.0);

int main(void)
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin>>a[i];
    ll ans=1,bad=1;
    rep(i,n){
        ans*=3;
        if(a[i]%2==0) bad*=2;
    }
    cout<<ans-bad<<endl;
    return 0;
}