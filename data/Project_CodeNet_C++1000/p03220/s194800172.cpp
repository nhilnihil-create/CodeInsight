#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	double t, a;
	cin >> n >> t >> a;
	double min_value = 1LL << 60;
	int min_index = -1;
	for (int i = 0; i < n; ++i) {
		double h;
		cin >> h;
		double diff = abs((t - h * 0.006) - a);
		if (diff < min_value) {
			min_value = diff;
			min_index = i;
		}
	}
	cout << min_index + 1 << endl;
}