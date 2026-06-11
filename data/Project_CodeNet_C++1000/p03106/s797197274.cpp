#include <bits/stdc++.h>
using namespace std;

int main() {
	int A, B, K;
	cin >> A >> B >> K;
	vector<int> vec;
	vec.push_back(1);
	for (int i = 2; i < 101; i++) {
		if (A % i == 0 && B % i == 0) {
			vec.push_back(i);
		}
	}
	reverse(vec.begin(), vec.end());
	cout << vec.at(K - 1) << endl;
}
