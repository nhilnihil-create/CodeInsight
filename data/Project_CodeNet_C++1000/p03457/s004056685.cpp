#include "bits/stdc++.h"

using namespace std;

int main() {
	int N;
	cin >> N ;
	vector<int>t(N+1); 
	vector<int>x(N+1); 
	vector<int>y(N+1);
	for (int n = 0;n < N;++n) {
		cin >> t[n+1] >> x[n+1]>>y[n+1];
	}
	vector<int>t2(N);
	vector<int>x2(N);
	vector<int>y2(N);
	for (int n = 0; n < N; ++n) {
		t2[n] = t[n + 1] - t[n];
		x2[n] = x[n + 1] - x[n];
		y2[n] = y[n + 1] - y[n]; 
		//cout << t2[n]<<x2[n]<< y2[n]<< endl;
	}
	for (int n = 0; n < N; ++n) {
		int x, y;
		if (x2[n] > 0) {
			x = x2[n];
		}
		else {
			x = -x2[n];
		}
		if (y2[n] > 0) {
			y = y2[n];
		}
		else {
			y = -y2[n];
		}
		//cout << t2[n]<<x << y <<endl;
		if (1 == t2[n]%2) {
			if (1 == (x+y) % 2) {
				if ( (x+y) <= t2[n]) {
					//
				}
				else {
					cout << "No" << endl;
					return 0;
				}
			}
			else {
				cout << "No" << endl;
				return 0;
			}
		}
		else {
			if (0 == (x + y) % 2) {
				if ((x + y) <= t2[n]) {
					//
				}
				else {
					cout << "No" << endl;
					return 0;
				}
			}
			else {
				cout << "No" << endl;
				return 0;
			}
		}
	}
	cout << "Yes" << endl;

	return 0;
}
