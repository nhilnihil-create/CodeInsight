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

const vector<pair<ll, ll>> lis = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int main(void) {
    ll H, W;
    ll maxi = 0;
    vector<string> A;
    vector<vector<ll>> D;
    queue<pair<ll, ll>> Q;
    cin >> H >> W;
    A.resize(H);
    D.resize(H, vector<ll>(W));
    rep(h, H) {
        cin >> A[h];
        rep(w, W) if(A[h][w] == '#') Q.emplace(h, w);
    }
    while(!Q.empty()) {
        auto current = Q.front();
        Q.pop();
        iter(i, lis) {
            auto next = i;
            next.first += current.first;
            next.second += current.second;
            if(0 > next.first || H <= next.first || 0 > next.second || W <= next.second) continue;
            if(A[next.first][next.second] == '.') {
                D[next.first][next.second] = D[current.first][current.second] + 1;
                A[next.first][next.second] = '#';
                Q.push(next);
            }
        }
    }
    rep(h, H) rep(w, W) maxi = max(maxi, D[h][w]);
    cout << maxi << endl;
    return 0;
}
