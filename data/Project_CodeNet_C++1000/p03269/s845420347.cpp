#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
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
    
    int l;
    cin >> l;
    vector<tuple<int, int, int>> ans;
    int n = 20;
    for (int i = 1; i <= n-1; ++i) ans.eb(i, i+1, 0);
    int power = 1;
    for (int i = 1; i <= n-1; ++i) {
        if (power * 2 <= l) {
            ans.eb(i, i+1, power);
            power *= 2;
        } else break;
    }
    int bit = l - power;
    int length = power;
    for (int i = 1; i <= n-1; ++i) {
        if ((bit>>(i-1)) & 1) {
            ans.eb(i, n, length);
            length += pow(2, i-1);
        }
    }
    int m = sz(ans);
    cout << n << " " << m << endl;
    rep(i, m) {
        int a, b, c;
        tie(a, b, c) = ans[i];
        cout << a << " " << b << " " << c << endl;
    }
}