#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, a;
	cin >> N;
	int Alice = 0;
	int Bob = 0;
	vector<int> vec(N);
	for (int i = 0; i < N; i++) {
		cin >> a;
		vec.at(i) = a;
	}
	sort(vec.begin(), vec.end());
	reverse(vec.begin(), vec.end());
	for (int j = 0; j < N; j++) {
		if (j % 2 != 0) {
			Bob += vec.at(j);
		}
		else {
			Alice += vec.at(j);
		}
	}
	cout << Alice - Bob << endl;
}
