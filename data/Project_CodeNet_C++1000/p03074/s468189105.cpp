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
    ll N, K;
    string S;
    cin >> N >> K >> S;
    vector<ll> ruiseki{0};
    S.push_back(S.back() == '0' ? '1' : '0');
    ll count = 0;
    rep(i, N) {
        count++;
        if(S[i] != S[i + 1]) {
            ruiseki.push_back(ruiseki.back() + count);
            count = 0;
        }
    }
    ll ans = 0;
    rep(i, ruiseki.size()) {
        ll temp = ruiseki[min(2 * K + i + (S.front() == '0' ? (i % 2 == 0 ? 0 : 1) : (i % 2 != 0 ? 0 : 1)), (ll)ruiseki.size() - 1)] - ruiseki[max(0LL, i + (S.front() == '0' ? (i % 2 == 0 ? -1 : 0) : (i % 2 != 0 ? -1 : 0)))];
        ans = max(ans, temp);
    }
    cout << ans << endl;
}
