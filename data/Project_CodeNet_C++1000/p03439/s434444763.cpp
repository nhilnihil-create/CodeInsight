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
map<string, int> mp = {{"Vacant", 0}, {"Male", 1}, {"Female", 2}};
bool check(int l, int r, int mid, vector<int> &vec){
    if(l % 2 == mid % 2){
        if(vec[l] == vec[mid]){
            return true;
        } else {
            return false;
        }
    } else {
        if(vec[l] == vec[mid]){
            return false;
        } else {
            return true;
        }
    }
}
int main(void){
    int n;
    cin >> n;
    vector<int> vec(n, -1);

    int l = 0;
    int r = n - 1;
    while(abs(l - r) > 1){
        if(vec[l] == -1){
            string in;
            cout << l << endl;
            cin >> in;
            if(mp[in] == 0){
                return 0;
            }
            vec[l] = mp[in];
        }
        if(vec[r] == -1){
            string in;
            cout << r << endl;
            cin >> in;
            if(mp[in] == 0){
                return 0;
            }
            vec[r] = mp[in];
        }
        int mid = (l + r) / 2;
        if(vec[mid] == -1){
            string in;
            cout << mid << endl;
            cin >> in;
            if(mp[in] == 0){
                return 0;
            }
            vec[mid] = mp[in];
        }
        if(check(l, r, mid, vec)){
            l = mid;
        } else {
            r = mid;
        }
    }
}