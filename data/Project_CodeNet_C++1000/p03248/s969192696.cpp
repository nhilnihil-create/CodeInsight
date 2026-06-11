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
#include <stack>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <math.h>
#include <tuple>
#include <iomanip>
#include <bitset>
#include <functional>
#include <cassert>
#include <random>

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

ll conbinationMemo[100][100];

void cmemoInit(){
    rep(i, 100){
        rep(j, 100){
            conbinationMemo[i][j] = -1;
        }
    }
}
 
ll nCr(ll n, ll r){
    if(conbinationMemo[n][r] != -1) return conbinationMemo[n][r];
    if(r == 0 || r == n){
        return 1;
    } else if(r == 1){
        return n;
    }
    return conbinationMemo[n][r] = (nCr(n - 1, r) + nCr(n - 1, r - 1));
}
 
ll nPr(ll n, ll r){
    r = n - r;
    ll ret = 1;
    for (ll i = n; i >= r + 1; i--) ret *= i;
    return ret;
}
//-----------------------ここから-----------
int main(void){
    string s;
    cin >> s;

    if(s.back() == '1' || s.front() == '0'){
        cout << -1 << endl;
        return 0;
    }
    s.pop_back();

    ll n = s.size();

    vector<pair<ll,ll>> e;
    ll root = 0;
    ll now = 1;
    rep(i, s.size()){
        if(s[i] != s[n - 1 - i]){
            cout << -1 << endl;
            return 0;
        }
        if(s[i] == '1'){
            e.push_back({root, now});
            root = now;
            now++;
        } else {
            e.push_back({root, now});
            now++;
        }
    }

    // if(n % 2 != 0){
    //     if(s[n / 2 + 1] == '1'){
    //         e.push_back({root, now});
    //         now++;
    //         root++;
    //     } else {
    //         e.push_back({root, now});
    //         now++;
    //     }
    // }
    rep(i, e.size()){
        cout << e[i].first + 1 << " " << e[i].second + 1 << endl;
    }
}
