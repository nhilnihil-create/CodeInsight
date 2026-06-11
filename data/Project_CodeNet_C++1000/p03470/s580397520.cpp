#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, d;
	cin >> N;
	vector<int> vec;
	int total = 1;
	for (int i = 0; i < N; i++) {
		cin >> d;
		vec.push_back(d);
	}
	sort(vec.begin(), vec.end());
	for (int j = 0; j < N - 1; j++) {
		if (vec.at(j) < vec.at(j + 1)) {
			total++;
		}
	}
	cout << total << endl;
}
