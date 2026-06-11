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

bool compare(pair<ll, ll> a, pair<ll, ll> b) {
    return a.second < b.second;
}

int main(void) {
    ll N;
    map<ll, ll> Am, Bm;
    vector<pair<ll, ll>> A, B;
    ll a, b;
    cin >> N;
    rep(i, N) {
        ll temp;
        cin >> temp;
        if(i % 2) Am[temp]++;
        else Bm[temp]++;
    }
    A = vector<pair<ll, ll>>(Am.begin(), Am.end());
    B = vector<pair<ll, ll>>(Bm.begin(), Bm.end());
    A.push_back({0, 0});
    B.push_back({0, 0});
    sort(A.begin(), A.end(), compare);
    sort(B.begin(), B.end(), compare);
    if(A.back().first == B.back().first) {
        a = N / 2 - A[A.size() - 2].second;
        b = N / 2 - B[B.size() - 2].second;
        if(a > b) a = N / 2 - A.back().second;
        else b = N / 2 - B.back().second;
    } else {
        a = N / 2 - A.back().second;
        b = N / 2 - B.back().second;
    }
    cout << a + b << endl;
    return 0;
}
