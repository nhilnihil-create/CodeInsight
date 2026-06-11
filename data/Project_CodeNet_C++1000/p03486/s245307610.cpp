/**
*    created: 03.07.2020 02:00:52
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

    string s, t;
    cin >> s >> t;

    auto ctoi2 = [&] (char c) {
        if (c >= 'a' && c <= 'z') return c - 'a';
        return -1;
    };

    int ma = -1;
    int mi = INF;

    rep(i,s.size()) {
        int tmp = ctoi2(s[i]);
        chmin(mi,tmp);
    }
    rep(i,t.size()) {
        int tmp = ctoi2(t[i]);
        chmax(ma,tmp);
    }

    bool ok = true;
    if (!(s.size() < t.size())) ok = false;
    else {
        map<char,int> mp;
        rep(i,t.size()) mp[t[i]]++;
        rep(i,s.size()) {
            if (mp[s[i]] == 0) ok = false;
        }
    }


    if (mi < ma || ok) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
