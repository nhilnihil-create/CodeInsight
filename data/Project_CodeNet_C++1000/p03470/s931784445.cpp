#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int N;
	cin >> N;

	vector<bool> v(100);
	for (int i = 0; i < N; i++) {
		int d;
		cin >> d;
		v.at(d - 1) = 1;
	}

	cout << count(v.begin(), v.end(), 1) << endl;
}