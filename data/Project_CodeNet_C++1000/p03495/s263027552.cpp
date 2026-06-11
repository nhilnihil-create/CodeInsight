/**
*    created: 03.07.2020 02:26:19
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

    int n, k;
    cin >> n >> k;
    map<int,int> mp;
    rep(i,n) {
        int a;
        cin >> a;
        mp[a]++;
    }
    if (mp.size() <= k) {
        cout << 0 << endl;
        return 0;
    }
    vector<int> v;
    for (auto p : mp) {
        v.push_back(p.second);
    }
    sort(all(v));
    int ans = 0;
    rep(i,mp.size()-k) {
        ans += v[i];
    }
    cout << ans << endl;
    return 0;
}