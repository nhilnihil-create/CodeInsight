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
int main(void){
    int a, b, q;
    cin >> a >> b >> q;

    vector<ll> s(a);
    vector<ll> t(b);
    for(int i = 0; i < a; i++) cin >> s[i];
    for(int i = 0; i < b; i++) cin >> t[i];
    vector<ll> qu(q);
    for(int i = 0; i < q; i++) cin >> qu[i];
    for(int i = 0; i < q; i++){
        ll x = qu[i];

        ll nearsb = lower_bound(all(s), x) - s.begin() - 1;
        ll nearsf = nearsb + 1;

        ll neartb = lower_bound(all(t), x) - t.begin() - 1;
        ll neartf = neartb + 1;

        ll ans = INF;

        if(nearsb >= 0 && neartb >= 0){
            ans = min(ans, max(abs(x - s[nearsb]), abs(x - t[neartb])));
        }

        if(nearsf < a && neartf < b){
            ans = min(ans, max(abs(x - s[nearsf]), abs(x - t[neartf])));
        }

        if(nearsb >= 0 && neartf < b){
            ans = min(ans, abs(x - s[nearsb]) * 2 + abs(x - t[neartf]));
            ans = min(ans, abs(x - s[nearsb]) + abs(x - t[neartf]) * 2);
        }
 
        if(nearsf < a && neartb >= 0){
            ans = min(ans, abs(x - s[nearsf]) * 2 + abs(x - t[neartb]));
            ans = min(ans, abs(x - s[nearsf]) + abs(x - t[neartb]) * 2);
        }

        cout << ans << endl;
    }
}   