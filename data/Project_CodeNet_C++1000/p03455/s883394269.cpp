#include"bits/stdc++.h"
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
using ll = long long;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vi = vector<int>;
using vii = vector<vi>;
using vl = vector<ll>;
using vll = vector<vl>;

int main() {
	ll a, b;
	cin >> a >> b;
	if ((a * b) % 2 == 0) {
		cout << "Even" << endl;
	}
	else {
		cout << "Odd" << endl;
	}
	return 0;
}