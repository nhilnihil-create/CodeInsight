#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	string s, t; cin >> s >> t; string test = t;
	sort(s.begin(), s.end()); sort(t.rbegin(), t.rend());
	
	if (s < t)cout << "Yes";
	else cout << "No";
	cout << endl;
	
	return 0;
}