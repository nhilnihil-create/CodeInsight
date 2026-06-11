#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod =(1e9)+7;
using P = pair<ll,ll>;


int main(){
   ll n;cin >>n;
   map<ll,int>p;
    for (ll i = 1; i*i <= n ; ++i) {
        if(i*i==n)p[i]++;
        else if(n%i==0){
            p[i]++;
            p[n/i]++;
        }
    }
    ll ans=0;
    for(auto u:p){
        ll k=(n-u.first)/u.first;
        if(k>0) {
            if (n % k == n / k)ans += k;
        }
    }
    cout <<ans <<endl;
    return 0;
}