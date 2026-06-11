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

bool good(string sleft, string sright, ll left, ll right) {
    if((left - right) % 2) return sleft == sright;
    else return sleft != sright;
}

int main(void) {
    ll N;
    ll l = 0, r;
    string L, R;
    cin >> N;
    r = N - 1;
    cout << l << endl;
    cin >> L;
    if(L == "Vacant") return 0;
    cout << r << endl;
    cin >> R;
    if(R == "Vacant") return 0;
    if(!good(L, R, l, r)) swap(L, R), l = r, r = N;
    while(true) {
        string temp;
        ll mid = (l + r) / 2;
        cout << mid << endl;
        cin >> temp;
        if(temp == "Vacant") break;
        if(good(L, temp, l, mid)) R = temp, r = mid;
        else L = temp, l = mid;
    }
    return 0;
}
