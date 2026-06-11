#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace  std;

int main() {
	int N, Q;
	cin >> N>>Q;
	string S;
	cin >> S;
	vector<int>Left(Q), Right(Q);
	for (int i = 0; i < Q; i++) {
		cin >> Left.at(i) >> Right.at(i);
	}
	vector<int>data(N+1);
	data.at(0) = 0;
	for (int i = 0; i < N-1; i++) {
		if (S[i] == 'A' && S[i + 1] == 'C') {
			data.at(i + 1) = data.at(i) + 1;
		}
		else {
			data.at(i + 1) = data.at(i);
		}
	}
	for (int i = 0; i < Q; i++) {
		cout << data.at(Right.at(i)-1) - data.at(Left.at(i)-1) << endl;
	}
	return 0;

}