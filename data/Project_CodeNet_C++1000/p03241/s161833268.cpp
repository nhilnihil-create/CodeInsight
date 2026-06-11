#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
typedef long long ll;
const int INT_INF = 1e9;
const ll INF = 1LL << 30;
const ll MOD = 1e9 + 7;

template<class T> void chmax(T& a, T b) { if(a < b) a = b; }
template<class T> void chmin(T& a, T b) { if(a > b) a = b; }

// 約数列挙
vector<long long> enum_divisors(ll N){
    vector<ll> res;
    for(ll i = 1; i * i <= N; i++){
        if(N % i == 0){
            res.push_back(i);
            if(N / i != i) res.push_back(N / i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

int main() {
    ll n, m; cin >> n >> m;

    V<ll> v = enum_divisors(m);
    ll ans = 0;
    for(int i = 0; i < (int)v.size(); i++){
        if(v[i] * n <= m) chmax(ans, v[i]);
    }
    cout << ans << endl;
}
