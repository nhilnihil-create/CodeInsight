#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
#define ld long double
#define ll long long

const int MOD =  1000000007;
const int IINF = INT_MAX;
const ll INF = 1LL << 60;

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
        if(v[i] * n <= m) ans = max(ans, v[i]);
    }
    cout << ans << endl;

    return 0;
}
