#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include <numeric>
#include<map>
#include<unordered_map>
#include <queue>
 
using namespace std;
using ll=long long;
#define rep(i,n)  for(ll i=0;i<n;++i)
#define all_map(itr,mp) for(auto itr=mp.begin();itr!=mp.end();itr++)
#define ALL(a) (a).begin(),(a).end()
 string toBin(int n){
    if(n == 1)return "1";
    else if(n == 0)return "0";

    return toBin(n/2)  + to_string(n%2);
}
int main(){
    ll n, k;
    cin >> n >> k;
    ll sum = 0;
    vector<ll> a(n);
    rep(i, n)cin >> a[i];
    vector<ll> b;
    rep(i, n){
        ll sum = 0;
        for(ll j=i; j<n; ++j)sum+=a[j], b.push_back(sum);
    }
    ll ans = 0;
   for(ll i=40; i>=0; --i){
        ll cnt = 0;
        ll x = ans|(1LL<<i);
        rep(j, b.size()){
            if((x&b[j])==x)cnt++;
        }
        if(cnt>=k)ans=x;
    }
    cout << ans << endl;
}