
// C - To Infinity

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int main() {
	string S;
	cin >> S;

	ll K;
	cin >> K;

	int seq_one = 0;
	char first_num;
	for (int i=0; i<S.size(); i++) {
		if (S[i] == '1') seq_one++;
		else {
			first_num = S[i];
			break;
		};
	}

	if (K <= seq_one) {
		cout << 1 << endl;
	} else {
		cout << first_num << endl;
	}

	return 0;
}