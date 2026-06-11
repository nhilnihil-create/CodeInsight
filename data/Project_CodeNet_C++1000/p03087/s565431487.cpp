#include<iostream>
#include<vector>
using namespace std;
int main() {
	int N, Q;
	string S;
	cin >> N >> Q >> S;
	vector<int> l(Q);
	vector<int> r(Q);
	for (int i = 0; i < Q; i++) {
		cin >> l[i] >> r[i];
	}
	vector<int> rec(N);
	int sum = 0;
	for (int i = 0; i < S.length() - 1; i++) {
		if (S[i] == 'A' && S[i + 1] == 'C') {
			sum++;
		}
		rec[i + 1] = sum;
	}
	for (int i = 0; i < Q; i++) {
		cout << rec[r[i] - 1] - rec[l[i] - 1] << endl;
	}
	return 0;
}