#include <bits/stdc++.h>
# define M_PI           3.14159265358979323846  /* pi */
using namespace std;

int main() {
	int  N, Y;
	cin >> N >> Y;
	

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			int k = N - i - j;
			if (0 <= k) {
				if ((10000 * i) + (5000 * j) + (1000 * k) == Y) {
					cout << i << " " << j << " " << k << endl;
					return 0;
				}
			}
			
		}
		
	}
	cout << "-1" << " " << "-1" << " " << "-1" << endl;
	
}