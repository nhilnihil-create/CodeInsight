#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
using namespace std;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vc = vector<char>;
using vb = vector<bool>;
using vs = vector<string>;
using vll = vector<long long>;
using vp = vector<pair<int, int>>;
using vvi = vector<vector<int>>;
using vvc = vector<vector<char>>;
using vvll = vector<vector<long long>>;
template<class T> inline bool chmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0;}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    cin >> s;
    int n = sz(s);
    string t = "";
    rep(i, n) {
        if (i+1 < n && s[i] == 'B' && s[i+1] == 'C') {
            i++;
            t += 'D';
        } else {
            t += s[i];
        }
    }
    
    int m = sz(t);
    ll cntA = 0;
    ll ans = 0;
    rep(i, m) {
        if (t[i] == 'A') cntA++;
        else if (t[i] == 'D') ans += cntA;
        else cntA = 0;
    }
    cout << ans << endl;
}