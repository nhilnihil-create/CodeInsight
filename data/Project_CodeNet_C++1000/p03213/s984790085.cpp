#include <bits/stdc++.h>
using namespace std;
constexpr long long MOD = 1000000007;
using ll = long long;
void factorization(long long n,map<long long ,long long>& mp){
    for(long long i=2;i*i<=n;i++){
        while(n%i==0){
            mp[i]++;
            n /= i;
        }
     }
     if(!(n == 1)) mp[n]++;
}
int main() {
    ll n;
    cin >> n;
    map<ll, ll> mp;
    for (ll i = 1; i <= n; i++) factorization(i, mp);
    ll over4 = 0;
    ll over2 = 0;
    ll over14 = 0;
    ll over24 = 0;
    ll over74 = 0;
    for (auto i : mp) {
        if (i.second >= 4) over4++;
    }
    for(auto i:mp){
        if (2 <= i.second && i.second <= 3) over2++;
    }
    for(auto i:mp){
        if (i.second >= 14) over14++;
    }
    for(auto i:mp){
        if (i.second >= 24) over24++;
    }
    for(auto i:mp){
        if (i.second >= 74) over74++;
    }
    ll ans = max(0LL,over4 * (over4 - 1) * (over4 + over2 - 2)/2);
    ans += max(0LL,over24 * (over4 + over2 - 1));
    ans += max(0LL,over14 * (over4 - 1));
    ans += over74;
    cout << ans << endl;
}
