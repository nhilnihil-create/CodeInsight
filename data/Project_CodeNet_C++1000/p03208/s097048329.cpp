#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, K, h;
	cin >> N >> K;
	vector<int> vec(N);
	int min;
	int check;
	for (int i = 0; i < N; i++) {
		cin >> h;
		vec.at(i) = h;
	}
	sort(vec.begin(), vec.end());
	min = vec.at(K - 1) - vec.at(0);
	for (int j = 1; j < N - K + 1; j++) {
		check = vec.at(K - 1 + j) - vec.at(j);
		if (check < min) {
			min = check;
		}
	}
	cout << min << endl;
}