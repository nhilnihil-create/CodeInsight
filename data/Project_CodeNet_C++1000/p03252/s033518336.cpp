#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define all(v) v.begin(), v.end()
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
    
    string s, t;
    cin >> s >> t;
    int n = sz(s);
    map<char, char> stot, ttos;
    rep(i, n) {
        if (stot.count(s[i])) {
            if (stot[s[i]] != t[i]) {
                cout << "No" << endl;
                return 0;
            }
        }
        if (ttos.count(t[i])) {
            if (ttos[t[i]] != s[i]) {
                cout << "No" << endl;
                return 0;
            }
        }
        stot[s[i]] = t[i];
        ttos[t[i]] = s[i];
    }
    cout << "Yes" << endl;
}