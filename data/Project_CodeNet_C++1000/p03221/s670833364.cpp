#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr long long MOD = 1000000007;
constexpr long long INF = 1LL << 60;
const long double PI = acosl(-1.0);
constexpr long double EPS = 1e-11;
template<class T> inline bool chmin(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
template<class T> inline bool chmax(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}
int main(){
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> pref(n+1);
    vector<ll> p(m), y(m);
    for (ll i = 0; i < m; i++) {
        cin >> p[i] >> y[i];
        pref[p[i]].push_back(y[i]);
    }
    for (ll i = 1; i < n + 1; i++) sort(pref[i].begin(), pref[i].end());
    for (ll i = 0; i < m;i++){
        cout << setfill('0') << right << setw(6) << p[i];
        cout << setfill('0') << right << setw(6) << (long long)(lower_bound(pref[p[i]].begin(), pref[p[i]].end(), y[i]) - pref[p[i]].begin() + 1) << endl;
        }
}