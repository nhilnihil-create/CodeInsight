#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main() {
	vector<int> A(6);
	for (int i = 0; i < 6; i++) {
		cin >> A[i];
	}
	int ans = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = i + 1; j < 5; j++) {
			if ((A[j] - A[i]) > A[5])ans++;
		}
	}
	if (ans == 0) {
		cout << "Yay!" << endl;
	}
	else {
		cout << ":(" << endl;
	}
	return 0;
}