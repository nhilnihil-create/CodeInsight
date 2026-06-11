/**
*    created: 03.07.2020 16:12:16
**/
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
// #include <boost/multiprecision/cpp_int.hpp>
// using bint = boost::multiprecision::cpp_int;
using namespace std;
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define pcnt(bit) __builtin_popcountll(bit)
template<class T> bool chmax(T &a, const T &b) {if (a < b) {a = b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if (b < a) {a = b; return 1;} return 0;}
const long double pi = acos(-1.0);
const int INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;

signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int p = -1;
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int l = t.size();
    if (n < l) {
        cout << "UNRESTORABLE" << endl;
        return 0;
    }
    vector<string> vec;
    rep(i,n-l+1) {
        string tmp = s.substr(i,l);
        bool ok = true;
        rep(j,l) if (tmp[j] != '?' && t[j] != tmp[j]) ok = false;
        if (ok) {
            p = 1;
            string ans = s.substr(0,i) + t + s.substr(i+l,n-i-l);
            rep(j,n) if (ans[j] == '?') ans[j] = 'a';
            vec.push_back(ans);
        }
    }
    if (p == -1) {
        cout << "UNRESTORABLE" << endl;
        return 0;
    }
    sort(all(vec));
    cout << vec[0] << endl;
    return 0;
}