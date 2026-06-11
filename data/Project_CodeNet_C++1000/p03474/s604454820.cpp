/**
*    created: 02.07.2020 00:01:55
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
const int MOD = 1000000007;
// const int MOD = 998244353;
const long double pi = acos(-1.0);
const int INF = 1LL << 60;

signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int a, b;
    cin >> a >> b;
    string s;
    cin >> s;

    if (s.size() != a + b + 1) {
        cout << "No" << endl;
        return 0;
    }

    auto ctoi = [&] (char c) {
        if (c >= '0' && c <= '9') return c - '0';
	    return -1;
    };
    
    rep(i,a) {
        if (ctoi(s[i]) == -1) {
            cout << "No" << endl;
            return 0;
        }
    }

    if (s[a] != '-') {
        cout << "No" << endl;
        return 0;
    }

    rep2(i,a+1,a+b) {
        if (ctoi(s[i]) == -1) {
            cout << "No" << endl;
            return 0;
        }
    }
    
    cout << "Yes" << endl;
    return 0;
}