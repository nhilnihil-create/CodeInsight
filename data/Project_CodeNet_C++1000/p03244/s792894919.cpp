#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
typedef long long ll;
typedef long double ld;
const long long INF = 1e18;
# define len(x) ((int)(x).size())
# define rep(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
# define reps(i, n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
# define rrep(i, n) for(int i=((int)(n)-1); i>=0; --i)
# define rreps(i, n) for(int i=((int)(n)); i>0; --i)
# define foreps(i, m, n) for(int i = m;i < n;i++)
# define ALL(x) (x).begin(), (x).end()
# define rall(x) (x).rbegin(), (x).rend()
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main() {
    ll n; cin >> n;
    vector<i64> v(n);
    map<int, int> odd, even;
    rep(i, n) {
        if (i % 2 == 0) {
            cin >> v[i];
            even[v[i]]++;
        }
        else {
            cin >> v[i];
            odd[v[i]]++;
        }
    }

    ll ev = 0, ev1 = 0, od = 0, od1 = 0;
    ll e1 = 0, e2 = 0, o1 = 0, o2 = 0;
    ll cnt = 0;
    for (auto itr = odd.begin(); itr != odd.end(); itr++) {
        if (itr->second > cnt) {
            cnt = itr->second;
            od = itr->first;
        }
    }
    o1 = cnt; cnt = 0;
    for (auto itr = odd.begin(); itr != odd.end(); itr++) {
        if (itr->second > cnt && itr->first != od) {
            cnt = itr->second;
            od1 = itr->first;
        }
    }
    o2 = cnt; cnt = 0;

    for (auto itr = even.begin(); itr != even.end(); itr++) {
        if (itr->second > cnt) {
            cnt = itr->second;
            ev = itr->first;
        }
    }
    e1 = cnt; cnt = 0;
    for (auto itr = even.begin(); itr != even.end(); itr++) {
        if (itr->second > cnt && itr->first != ev) {
            cnt = itr->second;
            ev1 = itr->first;
        }
    }
    e2 = cnt;

    if (ev == od) {
        cout << min(n - e1 - o2, n - e2 - o1) << endl;
    }
    else {
        cout << n - e1 - o1 << endl;
    }
}