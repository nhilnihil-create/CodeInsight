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

int main() {
    ll mx=1001001;
   vector<bool>isprime(mx,true);
   isprime[0]=false;isprime[1]=false;
   for(ll i=2;i<mx;i++) {
       if (isprime[i]) {
           for (ll j = i * 2; j < 1e6; j += i) {
               isprime[j] = false;
           }
       }
   }
   vector<int>a(mx,0);
    for (int i = 0; i < mx; ++i) {
        if(i%2==0)continue;
        if(isprime[i]&&isprime[(i+1)/2])a[i]++;
    }
    vector<ll>sum(mx+1,0);
    for (int i = 0; i < mx; ++i) {
        sum[i+1]=sum[i]+a[i];
    }
    ll q;cin >>q;
    for (int k = 0; k < q; ++k) {
        ll l,r;cin >>l>>r;
        cout <<sum[r+1]-sum[l]<<endl;
    }
}
