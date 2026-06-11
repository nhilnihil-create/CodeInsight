/**
*	created: 21.08.2020 14:28:05
**/
#include <bits/stdc++.h>
// #include <boost/multiprecision/cpp_int.hpp>
// using bint = boost::multiprecision::cpp_int;
using namespace std;
using ll = long long;
using P = pair<int,int>;
// #define endl '\n'
#define int long long
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define rep2(i,s,n) for (int i = (s); i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define pcnt(bit) __builtin_popcountll(bit)
template<class T> bool chmax(T &a, const T &b) {if (a < b) {a = b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if (b < a) {a = b; return 1;} return 0;}
const long double pi = acos(-1.0);
const int MAX = 1000010;
const int INF = LLONG_MAX;
const int MOD = 1000000007;
// const int MOD = 998244353;

signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n; cin >> n;
    int b = 2, t = 0;
    vector<int> v;
    if (n == 0) {cout << 0 << endl; return 0;}
    while (true) {
        if (n == 0) break;

        if (n % b != 0) {
            v.push_back(1);
            if (t % 2 == 0) n -= b/2;
            else n += b/2;
        }
        else v.push_back(0);

        t++; b *= 2;
    }
    reverse(all(v));
    for (auto p : v) cout << p;
    cout << endl;
    return 0;
}