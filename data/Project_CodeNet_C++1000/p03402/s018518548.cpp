#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
const ll INF = 1LL << 60;
const ll MOD = 1000000007;
template <class T>
bool chmax(T &a, const T &b) {
    return (a < b) ? (a = b, 1) : 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    return (b < a) ? (a = b, 1) : 0;
}

int main() {
    int a, b;
    cin >> a >> b;
    int h, w;
    h = w = 100;
    vector<string> ret(h, string(w, '.'));
    for (int i = 0; i < 100; i += 2) {
        for (int j = 0; j < 100 - 1; ++j) {
            ret[i][j] = '#';
        }
    }
    for (int i = 0; i < 100; ++i) {
        ret[i][0] = '#';
    }
    int xx = 2;
    int yy = 1;
    while (a != 1) {
        ret[yy][xx] = '#';
        a--;
        yy += 2;
        if (yy >= 100) {
            yy = 1;
            xx += 2;
        }
    }
    xx = 97;
    yy = 0;
    while (b != 1) {
        ret[yy][xx] = '.';
        b--;
        yy += 2;
        if (yy >= 100) {
            yy = 0;
            xx -= 2;
        }
    }
    cout << 100 << " " << 100 << endl;
    for (auto &s : ret) {
        cout << s << endl;
    }
    return 0;
}