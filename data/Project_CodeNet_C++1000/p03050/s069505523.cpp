#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P  = pair<int,int>;
using v  = vector<int>;
using vv = vector<v>;

int main(){
    ll n; cin >> n;
    
    ll ans = 0;
    
    for(ll i=1; i*i<=n; i++){
        if(n%i)continue;
        if(n/i-i<2)continue;
        
        ans += n/i -1;
    }
    
    cout << ans << endl;
    return 0;
}