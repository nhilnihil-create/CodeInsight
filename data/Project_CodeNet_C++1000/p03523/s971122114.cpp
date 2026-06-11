#include <bits/stdc++.h>
using namespace std;
int main() {
	string s;
	cin >> s;
	set<string> v = { "KIHBR","KIHBRA","KIHBAR", "KIHBARA", "KIHABR",
		"KIHABRA", "KIHABAR", "KIHABARA", "AKIHBR", "AKIHBRA", "AKIHBAR", "AKIHBARA",
		"AKIHABR", "AKIHABRA", "AKIHABAR","AKIHABARA" };
	if (v.count(s))cout << "YES" << endl;
	else cout << "NO" << endl;
}