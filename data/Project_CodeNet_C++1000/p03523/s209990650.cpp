#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	string s;
	cin >> s;
	if (s == "KIHBR" || s == "KIHABR" || s == "KIHBAR" || s == "KIHABAR"
			|| s == "AKIHBR" || s == "AKIHABR" || s == "AKIHBAR"
			|| s == "AKIHABAR" || s == "KIHBRA" || s == "KIHABRA"
			|| s == "KIHBARA" || s == "KIHABAR" || s == "AKIHABAR"
			|| s == "AKIHABRA" || s == "AKIHBARA" || s == "AKIHBRA"
			|| s == "AKIHABARA") {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	return 0;
}
