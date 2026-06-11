#include "bits/stdc++.h"
using namespace std;


//約数列挙
vector<long long> calc(long long N) {
	vector<long long> x;
	for (long long i= 1; i <= sqrt(N); i++) {
		if (0 == N % i) {
			x.push_back(i);
			if (N != i * i) {
				x.push_back(N / i);
			}
		}
	}
	return x;
}

int main() {
	long long N,M;
	cin >> N>>M;
	vector <long long > v = calc(M);
	std::sort(v.begin(), v.end(), std::greater<long long>());
	for (int n = 0;n<v.size();++n) {
		if (M >= v[n]*N) {
			cout << v[n]<<endl;
			break;
		}
	}
	return 0;
}
