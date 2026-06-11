/**
*	created: 10.08.2020 17:36:11
**/
#include <bits/stdc++.h>
// #include <boost/multiprecision/cpp_int.hpp>
// using bint = boost::multiprecision::cpp_int;
using namespace std;
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
const int INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;

// 素因数分解してmapに格納
map<int,int> mp;

void prime(int n) {
    if (n == 1) return;
    for (int i = 2; i*i<= n; i++) {
        if (n % i == 0) {
            prime(i);
            prime(n/i);
            return;
        }
    }
    mp[n]++;
    return;
}

signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n; cin >> n;
    rep2(i,2,n+1) prime(i);
    int cnt74 = 0, cnt2 = 0, cnt24 = 0, cnt4 = 0, cnt14 = 0;
    for (auto p : mp) {
        int m = p.second;
        if (m >= 74) {cnt74++; cnt2++; cnt24++; cnt4++; cnt14++;}
        else if (m >= 24) {cnt2++; cnt24++; cnt4++; cnt14++;}
        else if (m >= 14) {cnt2++; cnt4++; cnt14++;}
        else if (m >= 4) {cnt2++; cnt4++;}
        else if (m >= 2) cnt2++;
    }
    int ans = cnt74 + cnt14*(cnt4-1) + cnt24*(cnt2-1) + cnt4*max(cnt4-1,0ll)*(cnt2-2)/2;
    cout << ans << endl;
    return 0;
}