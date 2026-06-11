#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
ll factorial(int i) {       //階乗
    if (i == 0) return 1;
    return (factorial(i - 1)) * i;
}

int d(ll n) {
    if(n == 0) return 1;
    int count = 0;
    while(n != 0) {
        n /= 10;
        count++;
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    vector<ll> rui(n + 1);
    rui[0] = 0;
    map<ll, ll> mp;
    mp[0]++;
    rep1(i, n) {
        ll a;
        cin >> a;
        rui[i] += rui[i - 1] + a;
        mp[rui[i]]++;
    }
    ll ans = 0;
    for(auto p : mp) ans+= p.second * (p.second - 1) / 2;
    cout << ans << endl;
}