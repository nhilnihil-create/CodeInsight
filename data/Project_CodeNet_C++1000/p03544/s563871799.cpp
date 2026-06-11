#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
	int N;
	cin >> N;

	int l0 = 2;
	int l1 = 1;
	vector<ll> vec;
	vec.push_back(l0);
	vec.push_back(l1);
	for (int i = 1; i <= 86; i++) {
		vec.push_back(vec[i - 1] + vec[i]);
	}
	cout << vec[N] << endl;
	return 0;
}