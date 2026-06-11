#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<list>
#include<map>
#include<numeric>
#include<iomanip>
#define REP(i,m,n) for(int i=(int)(m);i<(int)(n);i++)
#define rep(i,n) REP(i,0,n)
#define ll long long

using namespace std;

/*小数点以下の長さを指定
cout << fixed << setprecision(15) << y << endl;
*/

//最大公約数
ll gcd(ll a, ll b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

//最小公倍数
ll lcm(ll a, ll b) {
	return a * b / gcd(a, b);
}


int main() {
	int n;
	cin >> n;
	vector<pair<double, string>>kane;
	rep(i, n){
		double x;
		string u;
		cin >> x >> u;
		kane.emplace_back(x, u);
	}

	double ans = 0;
	rep(i, kane.size()){
		if (kane[i].second == "JPY"){
			ans += kane[i].first;
		}
		else{
			ans += kane[i].first * 380000;
		}
	}

	cout << fixed << setprecision(10) << ans << endl;
	
	return 0;
}
