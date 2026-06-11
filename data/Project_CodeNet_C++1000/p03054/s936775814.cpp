#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define REP(i,n) for (int i = 1; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define vout(x) rep(i,x.size()) cout << x[i] << " "
template<class T> bool chmin(T &a, T b) {if(a>b) {a=b;return 1;}return 0;}
template<class T> bool chmax(T &a, T b) {if(a<b) {a=b;return 1;}return 0;}
using namespace std;
using vint = vector<int>;
using vvint = vector<vector<int>>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<int,int>;
const int inf = 1e9+7;
const ll inf_l = 1e18;
const int MAX = 1e6;

int main() {
    int h, w, n; cin >> h >> w >> n;
    int y, x; cin >> y >> x;
    string s, t; cin >> s >> t;
    reverse(all(s));
    reverse(all(t));
    P l = P(1,1), r = P(h,w);
    rep(i,n) {
        if (t[i] == 'L') r.second = min(w,r.second+1);
        if (t[i] == 'R') l.second = max(1,l.second-1);
        if (t[i] == 'U') r.first = min(h,r.first+1);
        if (t[i] == 'D') l.first = max(1,l.first-1);
        if (s[i] == 'L') l.second++;
        if (s[i] == 'R') r.second--;
        if (s[i] == 'U') l.first++;
        if (s[i] == 'D') r.first--;
        // cout << l.first << l.second << endl;
        // cout << r.first << r.second << endl;
        // cout << endl;
        if (l.first > r.first) {cout << "NO" << endl; return 0;}
        if (l.second > r.second) {cout << "NO" << endl; return 0;}
    }
    if (l.first <= y && y <= r.first && l.second <= x && x <= r.second) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}