#include <iostream>
#include <cmath>
#include <algorithm>
#include <string> //文字列
#include <iomanip> //doubleの桁数指定
#include <list> //前後に数値を入れれる配列



#define REP(i,m,n) for(int i = (int) (m);i < (int) (n);i++) //forの短縮
#define rep(i,n) REP(i,0,n) //REPが0の時
#define ll long long int

using namespace std;

double PI = 3.141592653589793; //円周率

//常設関数↓

//最大公約数
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

//最小公倍数
ll lcm(ll a, ll b) {
	return a * b / gcd(a, b);
}

//degree → radian
ll chg_DegRad(int deg) {
	return deg * PI / 180.0;
}

//radian → degree
ll chg_RadDeg(int rad) {
	return rad * 180.0 / PI;
}

//提出コード↓

ll n, m;
ll x[1010], y[1010], z[1010];
ll a[8][1010];
ll ans;


int main() {
	cin >> n >> m;
	rep(i, n) cin >> x[i] >> y[i] >> z[i];

	rep(i, n) {
		a[0][i] = x[i] + y[i] + z[i];
		a[1][i] = x[i] + y[i] + -z[i];
		a[2][i] = x[i] + -y[i] + z[i];
		a[3][i] = x[i] + -y[i] + -z[i];
		a[4][i] = -x[i] + y[i] + z[i];
		a[5][i] = -x[i] + y[i] + -z[i];
		a[6][i] = -x[i] + -y[i] + z[i];
		a[7][i] = -x[i] + -y[i] + -z[i];
	}
	rep(i, 8) {
		sort(a[i], a[i] + n);
		reverse(a[i], a[i] + n);
	}
	rep(i, 8) {
		ll ret = 0;
		rep(j, m) {
			ret += a[i][j];
		}
		ans = max(ans, ret);
	}
	cout << ans << endl;
	



	




	return 0;
}

