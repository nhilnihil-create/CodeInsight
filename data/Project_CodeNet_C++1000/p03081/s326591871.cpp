#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <numeric>
#include <functional>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define exrep(i, a, b) for(ll i = a; i <= b; i++)
#define out(x) cout << x << endl
#define exout(x) printf("%.10f\n", x)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define re0 return 0
const ll mod = 1000000007;
const ll INF = 1e16;
const ll MAX_N = 100010;

int main() {
    ll n, q;
    string s;
    cin >> n >> q >> s;

    vector<char> t(q), d(q);
    rep(i, q) {
        cin >> t[i] >> d[i];
    }

    // 最初マスiにいるゴーレムをゴーレムiと呼ぶ

    // 判定問題「ゴーレムxは左方向に消滅するか？」を二分探索で解く
    ll left1 = -1;
    ll right1 = n;
    while(right1 - left1 > 1) {
        ll x = (left1 + right1)/2;  // ゴーレムxが最初にいるマス
        ll pos = x;  // ゴーレムxがいまいるマス
        bool ok = false;  // ゴーレムxが左方向に消滅するならtrue
        rep(i, q) {
            if(s[pos] == t[i]) {
                if(d[i] == 'L') {
                    pos--;
                }
                else if(d[i] == 'R') {
                    pos++;
                }
            }
            if(pos < 0) {
                ok = true;
                break;
            }
        }
        if(ok) {
            left1 = x;
        }
        else {
            right1 = x;
        }
    }
    // ゴーレム0からゴーレムleft1までが左方向に消滅する

    // 判定問題「ゴーレムxは右方向に消滅するか？」を二分探索で解く
    ll left2 = -1;
    ll right2 = n;
    while(right2 - left2 > 1) {
        ll x = (left2 + right2)/2;  // ゴーレムxが最初にいるマス
        ll pos = x;  // ゴーレムxがいまいるマス
        bool ok = false;  // ゴーレムxが右方向に消滅するならtrue
        rep(i, q) {
            if(s[pos] == t[i]) {
                if(d[i] == 'L') {
                    pos--;
                }
                else if(d[i] == 'R') {
                    pos++;
                }
            }
            if(n <= pos) {
                ok = true;
                break;
            }
        }
        if(ok) {
            right2 = x;
        }
        else {
            left2 = x;
        }
    }
    // ゴーレムright2からゴーレムn-1までが右方向に消滅する
    
    // 最終的に消滅しないのはゴーレムright1からゴーレムleft2までのmax(0, left2 - right1 + 1)体
    out(max(0LL, left2 - right1 + 1));
    re0;
}