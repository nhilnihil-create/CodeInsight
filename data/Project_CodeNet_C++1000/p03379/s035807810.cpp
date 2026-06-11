#include<iostream>
#include<string>
#include<vector>
#include<numeric>
#include<math.h>
#include<algorithm>
#include<iomanip>
#include<list>
#include<bitset>
#include<sstream>
using namespace std;


int main() {

	long long N;
	cin >> N;

	vector<long long> X(N, 0);
	vector<long long> D(N, 0);
	for (long long i = 0; i < N; i++) {
		cin >> X[i];
		D[i] = X[i];
	}

	sort(D.begin(), D.end());

	long long v1 = D[N / 2 - 1];
	long long v2 = D[N / 2];

	for (long long i = 0; i < N; i++) {
		if (X[i] <= v1) {
			cout << v2 << endl;
		}
		else {
			cout << v1 << endl;
		}
	}

	return 0;
}