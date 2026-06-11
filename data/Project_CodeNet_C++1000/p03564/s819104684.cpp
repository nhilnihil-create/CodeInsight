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
    ll n,k;
    cin >>n>>k;
    ll ans=1;
    for (int i = 0; i < n; ++i) {
        ans=min(ans*2,ans+k);
    }
    cout <<ans <<endl;
    return 0;
}