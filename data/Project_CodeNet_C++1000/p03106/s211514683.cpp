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

ll f(ll n){
    ll sum=0;
    for(int i=1;i<=n;i++){
        if(n%i==0) sum++;
    }
    return sum;
}

int main(void)
{
    ll a,b,k; cin>>a>>b>>k;
    vector<ll> gcd;
    for(int i=1;i<=min(a,b);i++){
        if(a%i==0 && b%i==0) gcd.push_back(i);
    }
    reverse(all(gcd));
    cout<<gcd[k-1]<<endl;
    return 0;
}