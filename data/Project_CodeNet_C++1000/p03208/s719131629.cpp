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
    ll n,k; cin>>n>>k;
    vector<ll> a(n);
    rep(i,n) cin>>a[i];
    sort(all(a));
    ll ans=INF;
    for(int i=0; k-1+i<n ;i++){
        ans=min(ans,a[k-1+i]-a[i]);
    }

    cout<<ans<<endl;
    return 0;
}