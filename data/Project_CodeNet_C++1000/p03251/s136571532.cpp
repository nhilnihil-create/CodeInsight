#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<math.h>
#include<tuple>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
bool war(const vector <int >& x, const vector <int >& y) {
	for (int Z = -100; Z <= 100; ++Z) {
		bool is_ok = true;
		for (int i = 0; i < x.size(); ++i) {
			if (x[i] >= Z) is_ok = false;
		}
		for (int i = 0; i < y.size(); ++i) {
			if (y[i] < Z) is_ok = false;
		}
		if (is_ok) return false;
	}
	return true;
}
int main() {
	int N, M;
	cin >> N >> M;
	vector<int>x(N + 1), y(M + 1);
	cin >> x[0] >> y[0];
	rep(i, N)cin >> x[i + 1];
	rep(i, M)cin >> y[i + 1];
	if (war(x,y)) {
		cout << "War" << endl;
	}
	else {
		cout << "No War" << endl;
	}
	return 0;
}