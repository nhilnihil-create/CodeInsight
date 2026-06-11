#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, A, B, P;
	cin >> N >> A >> B;
	vector<int> vec(3);
	for (int i = 0; i < N; i++) {
		cin >> P;
		if (P <= A) {
			vec.at(0)++;
		}
		else if (A + 1 <= P && P <= B) {
			vec.at(1)++;
		}
		else {
			vec.at(2)++;
		}
	}
		sort(vec.begin(), vec.end());
		cout << vec.at(0) << endl;
}
