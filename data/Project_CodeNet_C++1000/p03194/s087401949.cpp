#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using vi = vector<int>;

int main(){
    ll n,p;cin>>n>>p;
    map<ll, int> mp;
    for(ll i=2; i*i<=p; i++){
        if(p%i==0){
            while(p%i==0){
                mp[i]++;
                p /= i;
            }
        }
    }
    if(p!=1)mp[p]++;
    
    ll ans = 1;
    
    for(auto m: mp){
        ll key = m.first;
        ll len = m.second;
        len /= n;
        while(len){
            ans *= key;
            len--;
        }
    }
    
    cout << ans << endl;
    return 0;
}