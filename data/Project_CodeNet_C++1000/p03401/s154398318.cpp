#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int N;
	cin >> N;

	vector<int> v(N+2);
	for (int i = 1; i <= N; i++) cin >> v.at(i);

	int sum = 0;
	for (int i = 1; i < v.size(); i++) {
		sum += abs(v.at(i) - v.at(i - 1));
	}

	for (int i = 1; i <= N; i++) {
		int n = sum;
		n -= (abs(v.at(i) - v.at(i - 1)) + abs(v.at(i + 1) - v.at(i)));
		n += abs(v.at(i + 1) - v.at(i - 1));
		cout << n << endl;
	}
}