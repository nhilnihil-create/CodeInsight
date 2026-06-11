#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, p;
	cin >> N;
	int total = 0;
	vector<int> vec(N);
	for (int i = 0; i < N; i++) {
		cin >> p;
		vec.at(i) = p;
	}
	sort(vec.begin(), vec.end());
	reverse(vec.begin(), vec.end());
	vec.at(0) /= 2;
	for (int j = 0; j < N; j++) {
		total += vec.at(j);
	}
	cout << total << endl;
}