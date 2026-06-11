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
#include <functional>
 
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
string s;
ll memo[100100][4] = {0};
ll dp(ll i, ll j){
    if(i == s.size() && j == 3) return 1;
    if(i == s.size()) return 0;
    if(memo[i][j] != -1) return memo[i][j];

    ll res = 0;
    if(s[i] == '?'){
        if(j != 3) res += dp(i + 1, j + 1);
        res %= MOD;
        res += dp(i + 1, j) * 3;
        res %= MOD;
    } else {
        if(s[i] == 'C' && j == 2){
            res += dp(i + 1, j + 1);
        } else if(s[i] == 'B' && j == 1){
            res += dp(i + 1, j + 1);
        } else if(s[i] == 'A' && j == 0){
            res += dp(i + 1, j + 1);
        }
        res %= MOD;
        res += dp(i + 1, j);
        res %= MOD;
    }
    res %= MOD;
    return memo[i][j] = res;
}
int main(void){
    cin >> s;
    for(int i = 0; i <= s.size(); i++){
        for(int j = 0; j < 4; j++){
            memo[i][j] = -1;
        }
    }
    cout << dp(0, 0) % MOD << endl;
}