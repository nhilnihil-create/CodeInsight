#include <bits/stdc++.h>
using namespace std;
 
using ll=long long;
 
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b)
#define pb push_back
#define eb emplace_back
#define a first
#define b second
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
const ll MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<ll> as(n+1);
    rep(i, n) {
        ll a; cin >> a;
        as[i+1] = as[i] + a; 
    }  
    unordered_map<ll, ll> mp;
    for(auto c :as) mp[c]++;
    ll cnt = 0;
    for (auto& p : mp) {
        ll c = p.second;
        cnt += c*(c-1)/2;
    }
    cout << cnt << endl;
    return 0;
}