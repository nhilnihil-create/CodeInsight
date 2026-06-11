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

    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    vector<ll> sum(n + 1, 0);

    rep(i, n){
        sum[i + 1] = sum[i] + a[i];
    }

    vector<ll> sums;
    for(int i = 0; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            sums.push_back(sum[j] - sum[i]);
            //cout << j << " " << i << " " <<sum[j] - sum[i] << endl;
        }
    }

    sort(all(sums), greater<ll>());
    ll ans = 0;
    vector<ll> vec = sums;
    for(ll i = 60; i >= 0; i--){
        ll cnt = 0;
        vector<ll> nvec;
        for(ll j = 0; j < vec.size(); j++){
            if(vec[j] & (1LL << i)){
                cnt++;
                nvec.push_back(vec[j]);
            }
        }

        if(cnt >= k){
            ans |= (1LL << i);
            vec = nvec;
        }
    }

    cout << ans << endl;
}