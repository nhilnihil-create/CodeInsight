#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
using namespace std;
const int mod = 1000000007;
#define ll long long

int main()
{
	string S, T;
	cin >> S >> T;
	bool f = true;
	string ans;
	for (int i = 0; i < S.size() - T.size() + 1; i++) {
		string tmp = S;
		f = true;
		for (int j = 0; j < T.size(); j++) {
			if (S[i + j] == '?' || S[i + j] == T[j]) {
				tmp[i + j] = T[j];
			}
			else {
				f = false;
				break;
			}
		}
		if (f) {
			for (int j = 0; j < tmp.size(); j++) {
				if (tmp[j] == '?') tmp[j] = 'a';
			}
			if (ans.empty() || tmp < ans) {
				ans = tmp;
			}
		}
	}
	if (ans.empty()) {
		cout << "UNRESTORABLE" << endl;
	}
	else {
		cout << ans << endl;
	}
}
