/**
*    created: 25.07.2020 06:50:45
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
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int dx2[8]={0, 1, 0, -1, 1, 1,-1, -1};
const int dy2[8]={1, 0,-1, 0, 1, -1, 1, -1};
const long double pi = acos(-1.0);
const int MAX = 1000010;
const int INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;

signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int prim[MAX];
    rep(i,MAX) prim[i] = -1;
    rep2(i,2,MAX) {
        if (prim[i] != -1) continue;
        int j = i + i;
        while (j < MAX) {prim[j]++; j += i;}
    }
    prim[1]++;
    prim[0]++;
    int cnt[MAX];
    rep(i,MAX) {
        if (prim[i] == -1) cnt[i] = 1;
        else cnt[i] = 0;
    }
    int alk[MAX];
    rep(i,MAX) alk[i] = 0;
    rep(i,MAX) {
        if (i*2-1 >= MAX) break;
        if (cnt[i] == 1 && cnt[i*2-1] == 1) alk[i*2-1] = 1;
    }
    rep2(i,1,MAX) alk[i] += alk[i-1];
    int n; cin >> n;
    rep(i,n) {
        int l, r; cin >> l >> r;
        cout << alk[r] - alk[l-1] << endl;
    }
    return 0;
}