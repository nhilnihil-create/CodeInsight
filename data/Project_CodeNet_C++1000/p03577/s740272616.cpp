#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	for(int i=0; i<8; i++){
		s.pop_back();
	}
	cout << s;
}