#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;

int main(){
    int n,m;
    cin >> n >> m;
    vector<ll> a(n),b(n+1,0);
    map<ll,ll> mp;
    rep(i,n){
        cin >> a[i];
        b[i+1] = b[i] + a[i];
    }

    rep(i,n+1){
        ll tmp = b[i] % m;
        mp[tmp]++;
    }
    
    ll ans = 0;
    for (auto e : mp){
        ans += (e.second * (e.second-1))/2;
    }

    cout << ans << endl;
    return 0;
}