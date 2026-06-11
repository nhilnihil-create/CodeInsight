#include <iostream>
#include <vector>
using namespace std;
int main(void) {
	string S;
	cin >> S;
	vector<string> a =
	{
		"KIHBR","KIHBRA","KIHBAR","KIHBARA",
		"KIHABR","KIHABRA","KIHABAR","KIHABARA",
		"AKIHBR","AKIHBRA","AKIHBAR","AKIHBARA",
		"AKIHABR","AKIHABRA","AKIHABAR","AKIHABARA"
	};
	bool ok = false;
	for (int i = 0; i < 16; ++i) {
		if (a[i] == S) ok = true;
	}
	cout << (ok ? "YES" : "NO") << endl;
	return 0;
}