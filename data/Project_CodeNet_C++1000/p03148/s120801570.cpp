/*
これを入れて実行
g++ code.cpp
./a.out
 */
 
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <deque>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <unordered_map>
#include <cmath>
#include <math.h>
#include <tuple>
#include <iomanip>
#include <bitset>
#include <functional>

#define all(x) (x).begin(),(x).end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
using namespace std;
typedef long long ll;
typedef long double ld;
 
int dy4[4] = {-1, 0, +1, 0};
int dx4[4] = {0, +1, 0, -1};
int dy8[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx8[8] = {0, 1, 1, 1, 0, -1, -1, -1};
 
const long long INF = 1LL << 62;
const ll MOD = 1e9 + 7;
 
bool greaterSecond(const pair<int, int>& f, const pair<int, int>& s){
    return f.second > s.second;
}
 
ll gcd(ll a, ll b){
	if (b == 0)return a;
	return gcd(b, a % b);
}
 
ll lcm(ll a, ll b){
    return a / gcd(a, b) * b;
}
 
ll nCr(ll n, ll r){
    if(r == 0 || r == n){
        return 1;
    } else if(r == 1){
        return n;
    }
    return (nCr(n - 1, r) + nCr(n - 1, r - 1));
}
 
ll nPr(ll n, ll r){
    r = n - r;
    ll ret = 1;
    for (ll i = n; i >= r + 1; i--) ret *= i;
    return ret;
}
 
//-----------------------ここから-----------
int main(void){
    ll n, k;
    cin >> n >> k;

    vector<pair<ll,ll>> vec(n);
    rep(i, n){
        ll t, d;
        cin >> t >> d;
        vec[i] = {d, t};
    }

    sort(all(vec), greater<pair<ll,ll>>());

    ll now = 0;
    map<ll,ll> mp;
    set<ll> uni;
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> other;
    for(int i = 0; i < k; i++){
        if(uni.find(vec[i].second) != uni.end()){
            other.push(vec[i]);
            mp[vec[i].second]++;
        } else {
            uni.insert(vec[i].second);
            mp[vec[i].second]++;
        }
        now += vec[i].first;
    }
    ll ans = now + (ll)uni.size() * (ll)uni.size();
    for(int i = k; i < n; i++){
        if(uni.find(vec[i].second) == uni.end()){
            if(other.empty()) continue;
            uni.insert(vec[i].second);
            now += vec[i].first;
            mp[vec[i].second]++;
            
            pair<ll,ll> rem = other.top();
            now -= rem.first;
            mp[rem.second]--;
            other.pop();

            ans = max(now + (ll)uni.size() * (ll)uni.size(), ans);
        }
    }
    cout << ans << endl;
}