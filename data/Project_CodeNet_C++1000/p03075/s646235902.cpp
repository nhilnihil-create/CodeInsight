#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	vector <int> d(5);
	for (int ii = 0; ii < 5; ++ii){
		cin >> d[ii];
	}

	int k;
	cin >> k;

	bool ok = true;
	for (int ii = 0; ii < 4; ++ii){
		for (int jj = ii + 1; jj < 5; ++jj){
			if (abs(d[ii]-d[jj]) > k){
				ok = false;
			}
		}
	}

	if (ok){
		cout << "Yay!" << "\n";
	} else {
		cout << ":(" << "\n";
	}


	return 0;
}
