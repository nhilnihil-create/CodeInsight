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
    ll white = 0;
    rep(i, H) {
        cin >> S[i];
        iter(c, S[i]) {
            if(c == '.') white++;
        }
    }
    vector<pair<ll, ll>> directions{
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1},
    };
    queue<pair<ll, ll>> Q;
    vector<vector<pair<ll, ll>>> prev(H, vector<pair<ll, ll>>(W, {-1, -1}));
    Q.emplace(0, 0);
    while(!Q.empty()) {
        pair<ll, ll> current = Q.front();
        Q.pop();
        iter(dir, directions) {
            pair<ll, ll> temp = current;
            temp.first += dir.first;
            temp.second += dir.second;
            if(temp.first < 0 || temp.first >= W || temp.second < 0 || temp.second >= H) continue;
            if(S[temp.second][temp.first] == '#') continue;
            if(prev[temp.second][temp.first].first != -1) continue;
            prev[temp.second][temp.first].first = current.first;
            prev[temp.second][temp.first].second = current.second;
            Q.push(temp);
        }
    }
    ll res = 2;
    pair<ll, ll> current = prev[H - 1][W - 1];
    if(current.first == -1) {
        cout << -1 << endl;
    } else {
        while(current != pair<ll, ll>{0, 0}) {
            current = prev[current.second][current.first];
            res++;
        }
        cout << white - res << endl;
    }
    return 0;
}
