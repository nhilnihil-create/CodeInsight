#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
	vector<int> kon(5);
	rep(i, 5) {
		cin >> kon[i];
	}
	int k;
	cin >> k;
	int count = 0;
	rep(i, 5) {
		rep(j, 5) {
			if (kon[i] - kon[j] > k) {
				count ++;
			}
		}
	}
	if (count > 0) {
		cout << ":(" << endl;
	}
	else {
		cout << "Yay!" << endl;
	}
}
		
