#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;

	int maxValue = 0;
	vector<int> P;
	for (int i = 0; i < N; i++) {
		int p;
		cin >> p;
		maxValue = max(maxValue, p);
		P.push_back(p);
	}

	int total = 0;
	for (int i = 0; i < N; i++) {
		total = total + P[i];
	}

	cout << total-maxValue/2 << endl;
}
