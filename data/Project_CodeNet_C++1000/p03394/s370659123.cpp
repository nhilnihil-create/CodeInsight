#include <bits/stdc++.h>


using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0; i<int(n); i++)
#define FOR(i,m,n) for(int i=int(m); i<int(n); i++)
#define ALL(obj) (obj).begin(),(obj).end()
#define VI vector<int>
#define VLL vector<long long>
#define VVI vector<vector<int>>
#define VVLL vector<vector<long long>>
#define VC vector<char>
#define VS vector<string>
#define VVC vector<vector<char>>
#define VB vector<bool>
#define VVB vector<vector<bool>>
#define fore(i,a) for(auto &i:a)

typedef pair <int, int> P;
template<class T> bool chmax(T &a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, T b) { if (a > b) { a = b; return true; } return false; }
const int  INF = 1 << 30;
const ll INFL = 1LL << 60;
const ll mod = 998244353;

ll gcd(ll x, ll y) {
	if (y == 0) return x;
	return gcd(y, x%y);
}



int main() {
	int n;
	cin >> n;

	VLL v;

	ll a = 1;
	ll sum = 0;

	if (n == 3) {
		cout << 2 << ' ' << 5 << ' ' << 63 << endl;
		return 0;
	}
	if (n == 4) {
		cout << 2 << ' ' << 5 << ' ' << 20 << ' ' << 63 << endl;
		return 0;
	}
	if (n == 5) {
		cout << 2 << ' ' << 5 << ' ' << 20 << ' ' << 30 << ' ' << 63 << endl;
		return 0;
	}

	REP(i, n) {
		while (true) {
			if (a % 2 == 0 || a % 3 == 0)break;
			a++;
		}
		v.push_back(a);
		sum += a;
		a++;
	}
	a++;

	if (sum % 6 == 0) {
		REP(i, n)cout << v[i] << ' ';
	}
	else if (sum % 6 == 2) {
		REP(i, n) {
			if (v[i] != 8)cout << v[i] << ' ';
		}
		if (a % 6 != 0) {
			a += 6 - a % 6;
		}
		cout << a << endl;
	}
	else if (sum % 6 == 3) {
		REP(i, n) {
			if (v[i] != 9)cout << v[i] << ' ';
		}
		if (a % 6 != 0) {
			a += 6 - a % 6;
		}
		cout << a << endl;
	}
	else {
		REP(i, n) {
			if (v[i] != 9)cout << v[i] << ' ';
		}
		while (true) {
			if (a % 6 == 4)break;
			a++;
		}
		cout << a << endl;
	}


	

}


