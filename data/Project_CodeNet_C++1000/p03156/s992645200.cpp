#include"bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int N, A, B;
	cin >> N >> A >> B;
	vector<int> contest(3);
	rep(i, N) {
		int P;
		cin >> P;
		if (P <= A) contest.at(0)++;
		else if (A < P && P <= B) contest.at(1)++;
		else contest.at(2)++;
	}
	cout << *min_element(contest.begin(),contest.end()) << endl;
	return 0;
}