#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;

int main() {        
	int v[3][3];
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			cin >> v[i][j];
		}
	}
	for (int i = 0; i <= 100; ++i) {
		int a = v[0][0] - i;
		if (a >= 0) {
			for (int j = 0; j <= 100; ++j) {
				int b = v[1][1]  - j;
				if (b >= 0) {
					for (int k = 0; k <= 100; ++k) {
						int c = v[2][2] - k;
				if (c >= 0) {
							bool d = 1;
							vector<int> x = {i,j,k};
							vector<int> y = {a,b,c};
							for (int e = 0; e < 3; ++e) {
								for (int m = 0; m < 3; ++m) {
									if (v[e][m] != x[e] + y[m]) {
										d = 0;
									}
								}
							}
							if (d) {
								cout << "Yes";
								return 0;
							}
						}
					}
				} 
			}
		}
	}
	cout << "No";
}



//a0 + b0   a0 + b1    a0 + b2
//a1 + b1   a1 + b1
                     //a2 + b2
