#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;

int main() {
	ll n, x,diff=100000000;
	cin >> n >> x;
	vector<ll>city(n);
	rep(i, n)cin >> city[i];
	/*１つしか都市がない場合はxとの絶対値を出力*/
	if (n == 1) { cout << abs(x - city[0]); return 0; }
	/*複数ある場合は、各都市の座標とxの座標の絶対値同士の最大公約数をとってあげる
	　そうすると、xからその座標までの距離が求まり、その最大公約数を求めるため
	　D*nが出て来る。それの最小値をとってあげると答えが出る*/
	rep(i, n - 1)diff = min(diff, gcd(abs(city[i] - x), abs(city[i + 1] - x)));
	cout << diff << endl;
	return 0;
}

