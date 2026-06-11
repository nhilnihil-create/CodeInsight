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
    ll N;
    ll ac = 0, bc = 0;
    ll ae, be;
    map<ll, ll> A, B;
    vector<pair<ll, ll>> Av, Bv;
    cin >> N;
    rep(i, N) {
        ll temp;
        cin >> temp;
        if(i % 2) A[temp]++, ac++;
        else B[temp]++, bc++;
    }
    Av = vector<pair<ll, ll>>(A.begin(), A.end());
    Bv = vector<pair<ll, ll>>(B.begin(), B.end());
    Av.push_back({0, 0});
    Bv.push_back({0, 0});
    sort(Av.begin(), Av.end(), [](pair<ll, ll> a, pair<ll, ll> b) { return a.second < b.second; });
    sort(Bv.begin(), Bv.end(), [](pair<ll, ll> a, pair<ll, ll> b) { return a.second < b.second; });
    if(Av.back().first == Bv.back().first) {
        ae = ac - Av[Av.size() - 2].second;
        be = bc - Bv[Bv.size() - 2].second;
        if(ae > be) ae = ac - Av.back().second;
        else be = bc - Bv.back().second;
    } else {
        ae = ac - Av.back().second;
        be = bc - Bv.back().second;
    }
    cout << ae + be << endl;
    return 0;
}
