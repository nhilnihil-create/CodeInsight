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
	string s;
	cin >> s;
	string Heisei = "Heisei";
	string TBD = "TBD";
	if (s[5] == '0'){
		if (s[6] == '1' || s[6] == '2' || s[6] == '3' || s[6] == '4'){
			cout << Heisei << endl;
		}
		else cout << TBD << endl;
		return 0;
	}
	else cout << TBD << endl;

	return 0;
}


