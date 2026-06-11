#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define ll long long
const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1);


int main(void)
{
    ll a,b,c,k; cin>>a>>b>>c>>k;
    ll m=max({a,b,c}),sum=a+b+c-m;
    rep(i,k) m*=2;
    sum+=m;
    cout<<sum<<endl;
    return 0;
}
