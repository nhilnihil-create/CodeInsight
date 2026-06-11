#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
//const int mod=998244353;
using P = pair<int,int>;
using Pll = pair<ll,ll>;
using ld=long double;

int main(){
    ll n;cin >>n;
    ll ans=0;
    for (ll i =1; i*i<=n; ++i) {
        if(n%i==0){
            ll a=n/i;
            ll b=i;
            a--;
            if(a>b){
                ans+=a;
            }
        }
    }
    cout <<ans <<endl;
}
