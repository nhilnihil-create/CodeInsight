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
    ll A, B, Q;
    vector<ll> shrines, temples;
    cin >> A >> B >> Q;
    rep(i, A) {
        ll s;
        cin >> s;
        shrines.push_back(s);
    }
    rep(i, B) {
        ll t;
        cin >> t;
        temples.push_back(t);
    }
    shrines.push_back(numeric_limits<ll>::min());
    shrines.push_back(numeric_limits<ll>::max());
    temples.push_back(numeric_limits<ll>::min());
    temples.push_back(numeric_limits<ll>::max());
    sort(shrines.begin(), shrines.end());
    sort(temples.begin(), temples.end());
    rep(i, Q) {
        ll x;
        ll shrine[2], temple[2];
        ll mini = numeric_limits<ll>::max();
        cin >> x;
        auto iter = lower_bound(shrines.begin(), shrines.end(), x);
        shrine[0] = *(iter - 1) - x;
        shrine[1] = *iter - x;
        iter = lower_bound(temples.begin(), temples.end(), x);
        temple[0] = *(iter - 1) - x;
        temple[1] = *iter - x;
        iter(j, shrine) {
            iter(k, temple) {
                ll temp = max(abs(j), abs(k));
                if(abs(j) > 100000000000 || abs(k) > 100000000000) continue;
                if(signbit(j) != signbit(k)) temp += 2 * min(abs(j), abs(k));
                mini = min(mini, temp);
            }
        }
        cout << mini << endl;
    }
    return 0;
}
