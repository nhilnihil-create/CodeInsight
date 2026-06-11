#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rep2(i,s,n) for(int i = (s); i < (n); ++i)
#define ll long long
#define ld long double
#define P pair<ll,ll>
#define all(v) v.begin(),v.end()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1.0);

int main(void)
{
    ll n; cin>>n;
    vector<ll> a(n+1,0);
    a[0]=2,a[1]=1;
    for(int i=2;i<=n;i++){
        a[i]=a[i-1]+a[i-2];
    }
    cout<<a[n]<<endl;
    return 0;
}