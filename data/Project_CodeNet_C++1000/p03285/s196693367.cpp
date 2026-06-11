#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

int main() { 
	int n;
	cin >> n;
	bool d = 0; // 7 11 15
	for (int i = 0; i <= 17; ++i) {
		for (int j = 0; j <= 25; ++j) {
			if (i * 7 + j * 4 == n) {
				d = 1;
			}
		}
	}
	if (d) {
		cout << "Yes";
	}else {
		cout << "No";
	}
}
