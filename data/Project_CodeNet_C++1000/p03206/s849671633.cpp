#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i < (int)(n); i++)
using ll = long long;

using namespace std;
int main() {
	int d;
	cin >> d;
	string s = "Christmas";
	string eve = "Eve";
	d -= 22;
	rep(i,3) {
		s += " " + eve;
	}
	rep(i, d) {
		rep(j, 4)s.pop_back();
	}
	cout << s << endl;
	return 0;
}
