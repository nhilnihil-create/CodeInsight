#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, x, a;
	cin >> N >> x;
	vector<int> vec(N);
	int total = 0;
	int count = 0;
	for (int i = 0; i < N; i++) {
		cin >> a;
		vec.at(i) = a;
	}
	sort(vec.begin(), vec.end());
	for (int j = 0; j < N; j++) {
		total += vec.at(j);
		if (total <= x && j < N - 1) {
			count++;
		}
		else if (total < x && j == N - 1) {
			break;
		}
		else if (total == x && j == N - 1) {
			count++;
		}
		else {
			break;
		}
	}
	cout << count << endl;
}