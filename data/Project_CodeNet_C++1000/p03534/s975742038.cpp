#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main() {
	string S;
	cin >> S;
	map<char, int>mp;
	int n = S.size();
	for (int i = 0; i < S.size(); i++) {
		mp[S[i]]++;
	}
	if (n == 1) {
		cout << "YES" << endl;
	}
	else if (n == 2) {
		if (S != "aa"&&S != "bb"&&S != "cc") {
			cout << "YES" << endl;
		}
		else cout << "NO" << endl;
	}
	else {
		if (n % 3 == 0) {
			if (mp['a'] == n / 3 && mp['b'] == n / 3 && mp['c'] == n / 3) {
				cout << "YES" << endl;
			}
			else cout << "NO" << endl;
		}
		else if (n % 3 == 2) {
			if (mp['a'] == n / 3 + 1 && mp['b'] == n / 3 + 1 && mp['c'] == n / 3) {
				cout << "YES" << endl;
			}
			else if (mp['a'] == n / 3 && mp['b'] == n / 3 + 1 && mp['c'] == n / 3 + 1) {
				cout << "YES" << endl;
			}
			else if (mp['a'] == n / 3 + 1 && mp['b'] == n / 3 && mp['c'] == n / 3 + 1) {
				cout << "YES" << endl;
			}
			else cout << "NO" << endl;
		}
		else {
			if (mp['a'] == n / 3 + 1 && mp['b'] == n / 3 && mp['c'] == n / 3) {
				cout << "YES" << endl;
			}
			else if (mp['a'] == n / 3 && mp['b'] == n / 3 + 1 && mp['c'] == n / 3) {
				cout << "YES" << endl;
			}
			else if (mp['a'] == n / 3 && mp['b'] == n / 3 && mp['c'] == n / 3 + 1) {
				cout << "YES" << endl;
			}
			else cout << "NO" << endl;
		}

	}
}
