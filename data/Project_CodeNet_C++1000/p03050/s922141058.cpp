#include <bits/stdc++.h>

using namespace std;
using ll =long long;
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
#define leftunique(a) {sort((a).begin(),(a).end());(a).erase(unique((a).begin(),(a).end()),(a).end());}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
static const ll INF = 1LL << 60;
//Write From this Line

int main()
{
	ll n;
	cin >> n;

	ll ans = 0;
	// TODO:約数を全部見る。　約数-1が行けるかどうかを調べる
	// 約数を調べるのはO(√N)
	for(ll i = 1; i * i <= n; i++){
		if(n % i == 0){
			// TODO i - 1が条件を満たすか
			ll num = i - 1;
			ll num2 = n / i;
			num2 --;
			if(num != 0){
				if((n / num) == (n % num)) {
					ans += num;
				}
			}
			if(num2 != 0){
				if((n / num2) == (n % num2)){
					ans += num2;
				}
			}
		}
	}
	if(n == 2) ans = 0;
	cout << ans << endl;
}
