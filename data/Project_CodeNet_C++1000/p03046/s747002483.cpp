//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using ld = long double;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;
template<class T> using PQ = priority_queue<T>;
template<class T> using PQG = priority_queue<T, vector<T>, greater<T> >;
const int INF = 100010001;
const ll LINF = (ll)INF*INF*10;
template<typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &p) { return is >> p.first >> p.second;}
template<typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) { return os << p.first << ' ' << p.second;}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m, k;
    cin >> m >> k;
    if(m == 1) {
        if(k) cout << -1 << endl;
        else {
            cout << "0 0 1 1" << endl;
        }
    }
    else {
        if(k >= (1<<m)) {
            cout << -1 << endl;
        } else {
            rep(i, 1<<m) {
                if(i != k) cout << i << ' ';
            }
            cout << k << ' ';
            for(int i = (1<<m)-1; i >= 0; --i) {
                if(i != k) cout << i << ' ';
            }
            cout << k << '\n';
        }
    }
}