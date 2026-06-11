#include"bits/stdc++.h"
using namespace std;

int64_t sum = 0;
vector<int64_t> a(90, 0);
int64_t luca(int64_t n) {
	if (a.at(n)) return a.at(n);
	sum = luca(n - 1) + luca(n - 2); a.at(n) = sum;
	return sum;
}

int main() {
	int N;
	cin >> N;
	a.at(0) = 2;
	a.at(1) = 1;
	cout << luca(N) << endl;
}