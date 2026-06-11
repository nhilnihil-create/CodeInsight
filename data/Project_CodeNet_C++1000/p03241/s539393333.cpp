#include<iostream>
#include<vector>
#include<string>
#define rep(i, start, end) for (int i = (int)start; i < (int)end; ++i)
#define rrep(i, start, end) for (int i = (int)start - 1; i >= (int)end; --i)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
template<typename T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return 0;}
template<typename T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return 0;}

vector<ll> factorize(ll x) {
    vector<ll> res;
    for (ll i = 1; i * i <= x; ++i) {
        if (x % i == 0) {
            res.push_back(i);
            if (i * i != x) {
                res.push_back(x / i);
            }
        }
    }
    return res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    vector<ll> divisors = factorize(M);
    ll ans = 0;
    for (auto& d : divisors) {
        if (M / d >= N) {
            chmax(ans, d);
        }
    }
    cout << ans << endl;
    return 0;
}