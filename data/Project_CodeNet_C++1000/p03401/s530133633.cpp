#include <iostream>
#include <cmath>
#include <algorithm>
#include <string> //文字列
#include <iomanip> //doubleの桁数指定 setprecision()
#include <list> //前後に数値を入れれる配列
#include <map> //map
#include <vector> //vecror

#define REP(i,m,n) for(ll i = (ll) (m);i < (ll) (n);i++) //forの短縮
#define rep(i,n) REP(i,0,n) //REPが0の時
#define ll long long int

using namespace std;

double PI = acos(-1); //円周率
ll mod = 1e9 + 7;


//提出コード



ll n, a[100010],Mny[100010],SUM,ans;

ll Z(ll N) {
	if (N < 0) return N * -1;
	else return N;
}


int main() {
	cin >> n;
	rep(i, n) {
		cin >> a[i];
		if (i == 0) Mny[i] = Z(a[i]);
		else Mny[i] = Z(a[i - 1] - a[i]);
	}
	Mny[n] = Z(a[n - 1]);
	rep(i, n + 1) {
		SUM += Mny[i];
	}
	rep(i, n) {
		if(i == 0) ans = SUM - Mny[i] - Mny[i + 1] + Z(a[i + 1]);
		else if(i == n - 1) ans = SUM - Mny[i] - Mny[i + 1] + Z(a[i - 1]);
		else ans = SUM - Mny[i] - Mny[i + 1] + Z(a[i - 1] - a[i + 1]);
		cout << ans << endl;
	}
	




	return 0;
}

