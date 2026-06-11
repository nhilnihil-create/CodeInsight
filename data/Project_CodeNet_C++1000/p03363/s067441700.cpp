#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    map<ll, ll> mp;
    mp[0]++;
    ll sum = 0;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        sum += a;
        mp[sum]++;
    }
    ll ans = 0;
    for(auto x : mp){
        ans += x.second*(x.second-1)/2;
    }
    cout << ans << endl;
    return 0;
}