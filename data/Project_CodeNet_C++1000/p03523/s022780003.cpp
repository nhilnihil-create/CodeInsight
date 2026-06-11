#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	string check[] = {"AKIHABARA",
			"AKIHABAR", "AKIHABRA", "AKIHBARA", "KIHABARA",
			"AKIHABR", "AKIHBAR", "AKIHBRA", "KIHABAR", "KIHABRA", "KIHBARA",
			"AKIHBR", "KIHABR", "KIHBAR", "KIHBRA",
			"KIHBR"};
	for(string i : check){
		if(s.compare(i) == 0){
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
}
