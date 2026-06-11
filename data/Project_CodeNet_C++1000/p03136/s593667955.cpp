#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, L;
	cin >> N;
	int total = 0;
	vector<int> vec(N);
	for (int i = 0; i < N; i++) {
		cin >> L;
		vec.at(i) = L;
	}
	sort(vec.begin(), vec.end());
	for (int j = 0; j < N - 1; j++) {
		total += vec.at(j);
	}
	if (vec.at(N - 1) < total) {
		cout << "Yes" << endl;
	}
	else if (vec.at(N - 1) >= total){
		cout << "No" << endl;
	}
}