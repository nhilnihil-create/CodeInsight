//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <x86intrin.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define V vector
template <typename T> bool chmin(T &a, const T &b) {if(a > b){a = b; return true;} return false;}
template <typename T> bool chmax(T &a, const T &b) {if(a < b){a = b; return true;} return false;}
template<typename A, size_t N, typename T> void Fill (A (&array)[N], const T & val) {fill ((T*)array, (T*)(array+N), val);}
V<int> dx = {-1, 1,  0, 0, -1, -1,  1, 1};
V<int> dy = { 0, 0, -1, 1, -1,  1, -1, 1};

int main () {
    map<string, int> mp;
    int n; cin >> n;
    rep(i, n) {
        string s; cin >> s;
        mp[s]++;
    }
    int m; cin >> m;
    rep(i, m) {
        string s; cin >> s;
        mp[s]--;
    }
    int ans = 0;
    for (auto p : mp) {
        chmax(ans, p.second);
    }
    cout << ans << endl;

    return 0;
}