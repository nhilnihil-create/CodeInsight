#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int N;
	cin >> N;

	vector<int> A(4);
	A.at(0) = N / 1000;
	A.at(1) = N / 100 % 10;
	A.at(2) = N / 10 % 10;
	A.at(3) = N % 10;

	for (int i = 0; i < (1 << 3); i++) {
		int sum = A.at(0);
		vector<char> v;

		for (int j = 0; j < 3; j++) {
			if (i & (1 << j)) {
				sum -= A.at(j + 1);
				v.push_back('-');
			}
			else {
				sum += A.at(j + 1);
				v.push_back('+');
			}
		}
		//cout << sum << endl;

		if (sum == 7) {
			for (int j=0;j<3;j++) cout << A.at(j) << v.at(j);
			cout << A.at(3) << "=7" << endl;
			return 0;
		}
	}
}