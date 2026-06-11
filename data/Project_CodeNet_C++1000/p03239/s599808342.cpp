#include<iostream>
#include<vector>
#include<string>
#include<cmath>


using namespace std;



int main() {
	int N;
	int T;
	int c[105];
	int t[105];
	int cmin;
	int tle = 0;
	
	cin >> N >> T;

	for (int i = 0; i < N; i++) {
		cin >> c[i] >> t[i];
	}

	cmin = c[0];
	for (int i = 0; i < N; i++) {
		if (t[i] > T) {
			tle += 1;
		}
		else {
			if (c[i] < cmin) {
				cmin = c[i];
			}
		}
	}

	if (tle == N) {
		cout << "TLE";
	}
	else
	{
		cout << cmin;
	}
}