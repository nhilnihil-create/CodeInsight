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

#define all(x) (x).begin(),(x).end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
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
ll n, m;
vector<ll> a;
string infs;
string minusinf;
string memo[10010];
string maxs(string f, string s){
    if(f[0] == '#'){
        return s;
    }
    if(s[0] == '#'){
        return f;
    }
    if(f.size() > s.size()){
        return f;
    } else if(f.size() < s.size()){
        return s;
    } else {
        if(f >= s){
            return f;
        } else {
            return s;
        }
    }
}
map<ll,ll> mp = {{1, 2}, {2, 5}, {3, 5}, {4, 4}, {5, 5}, {6, 6}, {7, 3}, {8, 7}, {9, 6}};
string rec(ll i){
    if(i == 0){
        return "";
    }
    if(memo[i] != "none") return memo[i];
    //cout << "i " << i << endl;
    string res = minusinf;
    rep(j, m){
        if(i - mp[a[j]] < 0) continue;
        res = maxs(res, rec(i - mp[a[j]]) + to_string(a[j]));
    }
    //cout << "r " << i << " " << res << endl;
    return memo[i] = res;
}

string test(){
    return "";
}

int main(void){
    cin >> n >> m;
    a.resize(m);
    rep(i, m) cin >> a[i];
    minusinf.push_back(char(35));

    rep(i, 10010){
        infs += '9';
        memo[i] = "none";
    }
    //cout << char(35) << endl;
    cout << rec(n) << endl;
}