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
    ll h, w, n;
    cin >> h >> w >> n;

    ll sx, sy;
    cin >> sx >> sy;

    string s, t;
    cin >> s >> t;

    // 高橋君が左方向に取り除けるか調べる
    ll cnt = 0;
    rep(i, n) {
        if(s[i] == 'L') {
            cnt++;
        }
        if(cnt >= sy) {
            out("NO");
            re0;
        }
        if(t[i] == 'R') {
            cnt--;
            if(cnt == -(w - sy + 1)) {
                cnt++;
            }
        }
    }

    // 高橋君が右方向に取り除けるか調べる
    cnt = 0;
    rep(i, n) {
        if(s[i] == 'R') {
            cnt++;
        }
        if(cnt > w - sy) {
            out("NO");
            re0;
        }
        if(t[i] == 'L') {
            cnt--;
            if(cnt == -sy) {
                cnt++;
            }
        }
    }

    // 高橋君が上方向に取り除けるか調べる
    cnt = 0;
    rep(i, n) {
        if(s[i] == 'U') {
            cnt++;
        }
        if(cnt >= sx) {
            out("NO");
            re0;
        }
        if(t[i] == 'D') {
            cnt--;
            if(cnt == -(h - sx + 1)) {
                cnt++;
            }
        }
    }

    // 高橋君が下方向に取り除けるか調べる
    cnt = 0;
    rep(i, n) {
        if(s[i] == 'D') {
            cnt++;
        }
        if(cnt > h - sx) {
            out("NO");
            re0;
        }
        if(t[i] == 'U') {
            cnt--;
            if(cnt == -sx) {
                cnt++;
            }
        }
    }
    
    out("YES");
    re0;
}