#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using pint = pair<int,int>;
ll mod = 1000000007,mod2 = 998244353;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL<<60;
ll gcd(ll a,ll b){
    if(b == 0) return a;
    else return gcd(b,a%b);
}

int main() {
    int n;
    cin >> n;
    ll rui[n+1];
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for(int i = 0;i < n;i++){
        rui[i+1] = rui[i] + a[i];
    }
    map<ll,ll> mp;
    for(int i = 0;i <= n;i++){
        mp[rui[i]]++;
    }
    ll ans = 0;
    for(auto i:mp){
        ll tmp = i.second;
        ans += tmp*(tmp-1)/2;
    }
    cout << ans << endl;
    return 0;
}