/*
これを入れて実行
g++ code.cpp
./a.out
 */
 
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
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
 
using namespace std;
typedef long long ll;
typedef long double ld;
 
int dy4[4] = {-1, 0, +1, 0};
int dx4[4] = {0, +1, 0, -1};
int dy8[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx8[8] = {0, 1, 1, 1, 0, -1, -1, -1};
 
const long long INF = 1LL << 60;
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
int n;
vector<int> c;
vector<int> pre;
ll memo[200100];
ll dp(int i){
    if(i == -1) return 1;
    if(i == 1) return 1;
    if(memo[i] != -1) return memo[i];

    ll res = 0;
    if(pre[i] == -1){
        res += dp(i - 1);
    } else {
        int dist = i - pre[i];
        if(dist == 1){
            res += dp(i - 1);
        } else {
            res += dp(pre[i]);
            res += dp(i - 1);
        }
    }
    res %= MOD;
    return memo[i] = res;
}

int main(void){
    cin >> n;
    c.resize(n);
    for(int i = 0; i < n; i++) cin >> c[i];

    for(int i = 0; i <= n; i++){
        memo[i] = -1;
    }

    unordered_map<int,int> mp;
    pre.resize(n, -1);
    for(int i = 0; i < n; i++){
        if(mp.count(c[i])){
            pre[i] = mp[c[i]];
            mp[c[i]] = i;
        } else {
            mp[c[i]] = i;
        }
    }



    cout << dp(n - 1) << endl;
}