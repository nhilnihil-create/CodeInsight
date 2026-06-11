#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	int N;
	cin >> N;

	vector <int> x(N);
	vector <int> y(N);
	vector <ll> h(N);
	ll hmin = 100100100100;
	for (int ii = 0; ii < N; ++ii){
		cin >> x[ii] >> y[ii] >> h[ii];
		hmin = min(hmin, h[ii]);
	}

	for (int cx = 0; cx <= 100; ++cx){
		for (int cy = 0; cy <= 100; ++cy){
			for (int ch = hmin; ch <= hmin + 201; ++ch){
				bool valid = true;
				for (int ii = 0; ii < N; ++ii){
					if (h[ii] != max(ch - abs(x[ii]-cx) - abs(y[ii]-cy), 0)){
						valid = false;
						break;
					}
				}
				if (valid){
					cout << cx << " " << cy << " " << ch << "\n";
					return 0;
				}
			}
		}
	}

	return 0;
}
