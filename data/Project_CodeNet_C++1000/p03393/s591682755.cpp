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
#include <tuple>
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
    string s;
    cin >> s;

    if(s == "zyxwvutsrqponmlkjihgfedcba") {
        out(-1);
        re0;
    }

    if(s.size() < 26) {
        cout << s;
        for(char c = 'a'; c <= 'z'; c++) {
            bool ok = true;  // cがsに現れなければtrue
            rep(i, s.size()) {
                if(s[i] == c) {
                    ok = false;
                    break;
                }
            }
            if(ok) {
                cout << c << endl;
                re0;
            }
        }
    }

    ll i;  // s[i]からs[25]をsの接尾辞であって文字が左から右に降順に並んでいるもののうち最長のものとする
    for(i = 25; i >= 1; i--) {
        if(s[i-1] < s[i]) {
            break;
        }
    }
    
    for(char c = s[i-1]; c <= 'z'; c++) {
        bool ok = true;  // cがs[0]からs[i-1]に現れなければtrue
        rep(j, i) {
            if(c == s[j]) {
                ok = false;
                break;
            }
        }
        if(ok) {
            s[i-1] = c;
            break;
        }
    }
    
    out(s.substr(0, i));
    re0;
}