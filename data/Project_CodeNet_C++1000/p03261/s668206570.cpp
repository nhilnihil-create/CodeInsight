#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<string> W(N);
	int rec = 0;
	for (int i = 0; i < N; i++) {
		cin >> W[i];
	}
	for (int i = 1; i < N; i++) {
		if (W[i - 1][W[i - 1].length() - 1] != W[i][0]) {
			rec++;
		}
	}
	sort(W.begin(), W.end());
	for (int i = 0; i < N - 1; i++) {
		if (W[i] == W[i + 1]) {
			rec++;
		}
	}
	if (rec == 0) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}