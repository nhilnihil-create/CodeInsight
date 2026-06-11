#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define MOD 1000000007

#define rep(i, n) for(ll (i) = 0LL;(i) < (ll)(n);(i)++)
#define rep2(i, s, e) for(ll (i) = (ll)(s);(i) < (ll)(e);(i)++)
#define repi(i, n) for(ll (i) = 0LL;(i) <= (ll)(n);(i)++)
#define repi2(i, s, e) for(ll (i) = (ll)(s);(i) <= (ll)(e);(i)++)
#define per(i, n) for(ll (i) = (ll)(n) - 1LL;(i) >= 0LL;(i)--)
#define per2(i, s, e) for(ll (i) = (ll)(s) - 1LL;(i) >= (ll)(e);(i)--)
#define peri(i, n) for(ll (i) = (ll)(n);(i) >= 0LL;(i)--)
#define peri2(i, s, e) for(ll (i) = (ll)(s);(i) >= (ll)(e);(i)--)
#define iter(i, it) for(auto &(i): (it))

template<typename T, typename U> ostream& operator<<(ostream &s, const pair<T, U> m) {
    cout << "(" << m.first << ", " << m.second << ")";
    return s;
}
template<typename T, typename U> ostream& operator<<(ostream &s, const map<T, U> m) {
    ll c = 0;
    cout << "{ ";
    iter(i, m) cout << i << (c++ == m.size() - 1 ? " " : ", ");
    cout << "}";
    return s;
}
template<typename T> ostream& operator<<(ostream &s, const vector<T> &v) {
    cout << "{ ";
    rep(i, v.size()) cout << v[i] << (i == v.size() - 1 ? " " : ", ");
    cout << "}";
    return s;
}
template<typename T> ostream& operator<<(ostream &s, const list<T> &v) {
    ll c = 0;
    cout << "{ ";
    iter(i, v) cout << i << (c++ == v.size() - 1 ? " " : ", ");
    cout << "}";
    return s;
}

int main(void) {
    ll H, W;
    vector<vector<ll>> a;
    vector<tuple<ll, ll, ll, ll>> b;
    cin >> H >> W;
    a.resize(H, vector<ll>(W));
    rep(i, H) rep(j, W) cin >> a[i][j];
    rep(i, H) {
        if(i % 2) {
            per(j, W) {
                if(a[i][j] % 2) {
                    if(!(i == H - 1 && j == 0)) {
                        ll y, x;
                        if(j == 0) {
                            a[i + 1][j] += 1;
                            y = i + 1;
                            x = j;
                        } else {
                            a[i][j - 1] += 1;
                            y = i;
                            x = j - 1;
                        }
                        b.emplace_back(i + 1, j + 1, y + 1, x + 1);
                    }
                }
            }
        } else {
            rep(j, W) {
                if(a[i][j] % 2) {
                    if(!(i == H - 1 && j == W - 1)) {
                        ll y, x;
                        if(j == W - 1) {
                            a[i + 1][j] += 1;
                            y = i + 1;
                            x = j;
                        } else {
                            a[i][j + 1] += 1;
                            y = i;
                            x = j + 1;
                        }
                        b.emplace_back(i + 1, j + 1, y + 1, x + 1);
                    }
                }
            }
        }
    }
    cout << b.size() << endl;
    iter(i, b) cout << get<0>(i) << ' ' << get<1>(i) << ' ' << get<2>(i) << ' ' << get<3>(i) << endl;
    return 0;
}
