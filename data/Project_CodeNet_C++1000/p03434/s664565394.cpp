#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main() {
	int Alice = 0;
	int Bob = 0;
	int N;
	cin >> N;
	vector<int> vec(N);

	for (int i = 0; i < N; i++) {
		cin >> vec.at(i);
	}

	sort(vec.begin(), vec.end(), greater<> ());

	for (int j = 0; j < N; j++) {
		if (j % 2 == 0) {
			Alice += vec.at(j);
		}
		else {
			Bob += vec.at(j);
		}
	}

	int Out = Alice - Bob;
	cout << Out;
}