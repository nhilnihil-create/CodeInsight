#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<string> s;
	s.push_back("KIHBR");
	s.push_back("KIHBRA");
	s.push_back("KIHBAR");
	s.push_back("KIHBARA");
	s.push_back("KIHABR");
	s.push_back("KIHABRA");
	s.push_back("KIHABAR");
	s.push_back("KIHABARA");
	s.push_back("AKIHBR");
	s.push_back("AKIHBRA");
	s.push_back("AKIHBAR");
	s.push_back("AKIHBARA");
	s.push_back("AKIHABR");
	s.push_back("AKIHABRA");
	s.push_back("AKIHABAR");
	s.push_back("AKIHABARA");
	string t;
	cin >> t;
	cout << (count(s.begin(), s.end(), t) ? "YES\n" : "NO\n");
	return 0;
}