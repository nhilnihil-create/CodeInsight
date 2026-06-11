#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
using P = pair<ll,ll>;
using ld=long double;

int main(){
    ll n;cin >>n;
    ll x;cin >>x;
    ll sum=0;
    ll mint=INF;
    for (int i = 0; i < n; ++i) {
        ll m;cin >>m;
        mint=min(m,mint);
        sum+=m;
    }
    x-=sum;
    ll ans=0;
    ans+=n;
    ans+=x/mint;
    cout <<ans <<endl;
    return 0;
}