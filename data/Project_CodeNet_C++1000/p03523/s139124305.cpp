#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i < (int)(n); i++)
using ll = long long;
using namespace std;

int main() {
	string s;
	bool ans = false;
	cin >> s;
	string match_s[16] = { "AKIHABARA","KIHABARA","AKIHBARA","AKIHABRA","AKIHABAR",
						"AKIHABR","AKIHBRA","AKIHBRA","KIHABRA","KIHBARA","KIHABAR",
						"AKIHBR","KIHABR","KIHBAR","KIHBRA","KIHBR" };
	for (string t : match_s) if (s == t)ans = true;

	if (ans) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}

	return 0;
}
