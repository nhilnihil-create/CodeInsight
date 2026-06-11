#include <string>
#include <vector>
#include <iostream>
using namespace std;
int main() {
	string S;
	cin >> S;
	int N = S.size();
	S = "0" + S;
	bool ok = true;
	for (int i = 0; i <= N; ++i) {
		if (S[i] != S[N - i]) {
			ok = false;
		}
	}
	if (S[1] == '0') ok = false;
	if (!ok) {
		cout << "-1" << endl;
	}
	else {
		vector<int> seq;
		for (int i = 1; i * 2 <= N; ++i) {
			if (S[i] == '1') {
				seq.push_back(i);
			}
		}
		seq.push_back(N);
		for (int i = 1; i < seq.size(); ++i) {
			cout << seq[i - 1] << ' ' << seq[i] << endl;
			for (int j = seq[i - 1] + 1; j < seq[i]; ++j) {
				cout << j << ' ' << seq[i] << endl;
			}
		}
	}
	return 0;
}