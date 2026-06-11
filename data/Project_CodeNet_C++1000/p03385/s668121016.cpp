#include <bits/stdc++.h>
using namespace std;

int main() {
	string s; cin >> s;
	set<char> n;
	n.insert(s[0]);
	n.insert(s[1]);
	n.insert(s[2]);
	if(n.size()==3) cout << "Yes";
	else cout << "No";
	cout << endl;
}