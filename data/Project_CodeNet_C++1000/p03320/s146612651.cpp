#include "bits/stdc++.h"
using namespace std;

double Snuke(long long X) {
	double Y = 0;
	long long Z = X;
	while (Z) {
		Y += Z % 10;
		Z /= 10;
	}
	return (double)X / Y;
}

int main() {
	int K;
	cin >> K;
	vector<long long> V;
	for (int i = 0; i < 16; i++) {
		for (int j = 1; j <= 1000; j++) {
			if (i == 0 && j == 1) continue;
			V.push_back(j * pow(10, i) - 1);
		}
	}
	sort(V.begin(), V.end());
	V.erase(unique(V.begin(), V.end()), V.end());
	for (int i = 0; i < V.size(); i++) {
		for (int j = i + 1; j < V.size(); j++) {
			if (Snuke(V[i]) > Snuke(V[j])) {
				V.erase(V.begin() + i);
				i--;
				break;
			}
		}
	}
	for (int i = 0; i < K; i++) {
		cout << V[i] << endl;
	}
}