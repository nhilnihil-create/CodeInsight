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
int n, q;
string s;
bool check(vector<pair<char,char>> td, int mid, int type){
    int pos = mid;
    char nowchar = s[mid];
    bool res = false;
    for(int i = 0; i < q; i++){
        if(td[i].first == nowchar){
            if(td[i].second == 'L'){
                pos--;
            } else {
                pos++;
            }
            if(pos == -1){
                if(type == 0) res = true;
                break;
            }
            if(pos == n){
                if(type == 1) res = true;
                break;
            }
            nowchar = s[pos];
        }
    }

    return res;
}
int main(void){
    cin >> n >> q;
    cin >> s;

    vector<pair<char,char>> td(q);
    for(int i = 0; i < q; i++){
        cin >> td[i].first >> td[i].second;
    }

    int ok = -1;
    int ng = n;
    while(abs(ok - ng) > 1){
        int mid = (ok + ng) / 2;
        if(check(td, mid, 0)){
            ok = mid;
        } else {
            ng = mid;
        }
    }

    int ans = n - ok;

    ok = n;
    ng = -1;

    while(abs(ok - ng) > 1){
        int mid = (ok + ng) / 2;
        if(check(td, mid, 1)){
            ok = mid;
        } else {
            ng = mid;
        }
    }

    ans -= (n - ok + 1);

    cout << ans << endl;

}   