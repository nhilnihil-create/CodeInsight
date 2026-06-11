#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	string S;
	cin >> S;

	if (S[0] != 'A') {
		cout << "WA" << endl;
		return 0;
	}

	int nc = 0;
	int ic = -1;
	for (int i = 2; i <= S.size()-2; i++) {
		if (S[i] == 'C') {
			nc++;
			ic = i;
		}
	}
	if (nc != 1) {
		cout << "WA" << endl;
		return 0;
	}

	for (int i = 1; i < S.size(); i++) {
		if (i == ic) continue;
		if (isupper(S[i])) {
			cout << "WA" << endl;
			return 0;
		}
	}

	cout << "AC" << endl;

	return 0;
}
