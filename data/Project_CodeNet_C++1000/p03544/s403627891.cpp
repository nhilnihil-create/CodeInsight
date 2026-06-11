#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int N;
	cin >> N;

	vector<int64_t> v(2);
	v.at(0) = 2;
	v.at(1) = 1;
	for (int i = 2; i <= N; i++) {
		v.push_back(v.at(i - 1) + v.at(i - 2));
	}

	cout << v.at(N) << endl;
}