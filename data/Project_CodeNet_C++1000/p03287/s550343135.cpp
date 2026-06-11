#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
using ll = long long;
using P = pair<int, int>;
ll GCD(ll a, ll b) { return b?GCD(b, a%b):a; }
ll LCM(ll a, ll b) { return a/GCD(a, b)*b; }

ll n, m;

int main() {
    cin >> n >> m;
    vector<ll> A(n, 0);
    for(int i = 0; i < n; ++i) {
        cin >> A.at(i);
    }

    vector<ll> sumA(n+1, 0);
    for(int i = 0; i < n; ++i) {
        sumA.at(i+1) += sumA.at(i) + A.at(i);
    }
    map<ll, ll> cnt;
    for(int i = 0; i <= n; ++i) {
        ll ch = sumA.at(i) % m;
        cnt[ch]++;
    }

    ll ans = 0;
    for(auto mp : cnt) {
        ll cc = mp.second;
        ans += cc*(cc-1)/2;
    }
    cout << ans << endl;
}