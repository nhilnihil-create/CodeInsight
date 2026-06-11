#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

int main() {
	int n, m, X, Y;
	cin >> n >> m >> X >> Y;
	vector<int> x(n);
	vector<int> y(m);
	//bool a = 1;
	//bool b = 1;
	for (int i = 0; i < n; ++i) {
		cin >> x[i];
		//if (x[i] == X) {
	//		a = 0;
		//}
	}
	for (int i = 0; i < m; ++i) {
		cin >> y[i];
	//	if (y[i] == Y) {
	//		b = 0;
		//}
	}
	sort(x.begin(),x.end());
	sort(y.begin(),y.end());
	if (x[n - 1] < y[0] && X < Y && X < y[0] && Y > x[n - 1]) {
		cout << "No War";
	}else {
		cout << "War";
	}
}
