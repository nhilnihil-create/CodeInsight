#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int N;
	cin >> N;

	vector<int> v(N);
	for (int i = 0; i < N; i++) cin >> v.at(i);
	sort(v.begin(), v.end());

	int A, B;
	A = 0;
	B = 0;

	for (int i = N - 1; i >= 0; i--) {
		if ((N % 2) != (i % 2)) A += v.at(i);
		else B += v.at(i);
	}

	cout << A - B << endl;
}