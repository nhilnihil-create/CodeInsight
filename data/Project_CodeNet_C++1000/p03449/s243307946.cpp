#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int N;
	cin >> N;

	vector<int> A(N), B(N);
	for (int i = 0; i < N; i++) cin >> A.at(i);
	for (int i = 0; i < N; i++) cin >> B.at(i);


	int sum = A.at(0);
	for (int i = 0; i < N; i++) sum += B.at(i);
	vector<int> v = { sum };

	for (int i = 1; i < N; i++) {
		int n = v.at(i - 1);
		n = n - B.at(i - 1) + A.at(i);
		v.push_back(n);
	}
	sort(v.begin(), v.end());

	cout << v.at(v.size() - 1) << endl;
}