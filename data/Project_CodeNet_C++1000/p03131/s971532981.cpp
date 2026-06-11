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
    ll k, a, b;
    cin >> k >> a >> b;
    ll ans = 0;
    ll bis = 1;
    ll money = 0;
    if (b - a <= 2){
        cout << k + 1 << endl;
        return 0;
    } else {
        for (ll i = 0; i < k;i++){
            if (bis < a) bis++;
			else {
                if (i ==k-1) {
                    bis++;
                }
                else{
                    bis -= a;
                    bis += b;
                    i++;
                }
            }
        }
    }
    cout << bis << endl;
}