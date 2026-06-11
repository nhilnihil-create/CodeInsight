#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,n) for(int i=(a); i<(n); i++)
#define all(v) v.begin(), v.end()
#define fi first
#define se second
using namespace std;
using ll = long long;
using P = pair<int ,int>;
const int INF = 1e9;
const int MOD = 1e9+7;

void print() { cout << endl; }
template <class Head, class... Tail> void print(Head&& head, Tail&&... tail) { cout << head << ((sizeof...(tail)!=0)?" ":""); print(forward<Tail>(tail)...); }
template <class T> void print(vector<T> &vec) { for (auto& a : vec) { cout << a << ((&a!=&vec.back())?" ":""); } cout << endl; }
template <class T> void print(vector<vector<T>> &df) { for (auto& vec : df) { print(vec); } }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // 二次元累積和？
    int n, m, q; cin >> n >> m >> q;
    vector<vector<int>> a(n, vector<int>(n, 0));
    rep(i, m) {
        int x, y; cin >> x >> y;
        x--; y--;
        a[y][x]++;
    }

    vector<vector<int>> s(n+1, vector<int>(n+1, 0));
    rep(i, n) rep(j, n) {
        s[i+1][j+1] = s[i+1][j]+s[i][j+1]-s[i][j]+a[i][j];
    }

    // print();
    // print(s);

    // s[i][j] = iまでに終わる列車のうち、j以降から出発する列車の本数

    rep(i, q) {
        int x, y; cin >> x >> y;
        print(s[y][y]-s[y][x-1]);
    }
}