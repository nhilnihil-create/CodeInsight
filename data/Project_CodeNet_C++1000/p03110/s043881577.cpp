#include "bits/stdc++.h"
using namespace std;

int main() {
	int N;
	cin >> N;
	double ans = 0;
	for (int n = 0;n<N;++n) {
		double x;
		string u;
		cin >> x >> u;
		if ("JPY" == u) {
			ans += x;
		}
		else {
			ans += 380000.0*x;
		}
	}
	//printf("%.10f\n",ans);
	cout << (ans) / 1.0 << endl;
}