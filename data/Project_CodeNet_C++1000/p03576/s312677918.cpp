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
    ll n, K;
    cin >> n >> K;
    vector<ll> x(n);
    vector<ll> y(n);
    vector<pair<ll,ll>> vec(n);

    rep(i, n){
        cin >> x[i] >> y[i];
        vec[i] = {x[i], y[i]};
    }

    sort(all(x));
    sort(all(y));
    ll ans = INF;
    for(int x1 = 0; x1 < n; x1++){
        for(int x2 = x1 + 1; x2 < n; x2++){
            for(int y1 = 0; y1 < n; y1++){
                for(int y2 = y1 + 1; y2 < n; y2++){
                    int cnt = 0;
                    for(int i = 0; i < n; i++){
                        if(vec[i].first >= x[x1] && vec[i].first <= x[x2]){
                            if(vec[i].second >= y[y1] && vec[i].second <= y[y2]){
                                cnt++;
                            }
                        }
                    }

                    if(cnt >= K){
                        ans = min(ans, abs(x[x1] - x[x2]) * abs(y[y1] - y[y2]));
                    }
                }
            }
        }
    }
    cout << ans << endl;
}