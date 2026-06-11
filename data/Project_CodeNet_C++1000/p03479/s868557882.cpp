#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
template<class T>using numr=std::numeric_limits<T>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const int INF = 1e9;
const ll LLINF = 1e16;
const int mod = 1e9 + 7;
const int MOD2 = 998244353;

template< typename T >
istream &operator>>(istream &is, vector< T > &v) {
    for(T &in : v) is >> in;
    return is;
}
template< typename T >
ostream &operator<<(ostream &os, const vector< T > &v) {
    for(int i = 0; i < (int) v.size(); i++) {
        os << v[i] << (i + 1 != v.size() ? " " : "");
    }
    return os;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    ll x , y;
    cin >> x >> y;
    ll ans = 0;

    while(x<=y){
        x *= 2;
        ans++;
    }
    cout << ans << endl;
}