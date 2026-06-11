#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(void) {
	int n,i,j,c=0;
	cin >> n;
	vector<int> h(n);
	rep(i, n) {
		cin >> h[i];
	}

	rep(i, n) {
		if (h[i] == 0)continue;
		for (j = i; j < n && h[j]>0; j++) {
			h[j]--;
		}
		c++;
		if (h[i] > 0)i--;
	}
	cout << c << endl;
	return 0;
}