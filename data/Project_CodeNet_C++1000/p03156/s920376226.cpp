#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	int N, A, B;
	cin >> N >> A >> B;
	vector<int>P(N);
	for (int i = 0; i < N; i++) cin >> P.at(i);
	int E = 0, M = 0, D = 0;
	for (int i = 0; i < N; i++) {
		if (P.at(i) <= A) E++;
		else if (P.at(i) > A && P.at(i) <= B) M++;
		else D++;
	}
	cout << min({ E, M, D }) << endl;
}