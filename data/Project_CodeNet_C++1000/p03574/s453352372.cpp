#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define MOD 1000000007LL

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
    cin >> H >> W;
    vector<string> S(H);
    rep(i, H) cin >> S[i];
    rep(h, H) {
        rep(w, W) {
            if(S[h][w] == '#') {
                cout << '#';
            } else {
                ll ans = 0;
                if(w > 0 && S[h][w - 1] == '#') ans++;
                if(w < W - 1 && S[h][w + 1] == '#') ans++;
                if(h > 0 && S[h - 1][w] == '#') ans++;
                if(h < H - 1 && S[h + 1][w] == '#') ans++;
                if(h < H - 1 && w < W - 1 && S[h + 1][w + 1] == '#') ans++;
                if(h > 0 && w > 0 && S[h - 1][w - 1] == '#') ans++;
                if(h > 0 && w < W - 1 && S[h - 1][w + 1] == '#') ans++;
                if(h < H - 1 && w > 0 && S[h + 1][w - 1] == '#') ans++;
                cout << ans;
            }
        }
        cout << endl;
    }
    return 0;
}
