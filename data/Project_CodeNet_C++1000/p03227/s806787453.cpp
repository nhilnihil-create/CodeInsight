#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

string s;
int main() {
	cin >> s;
	if(s.size()==3) reverse(s.begin(), s.end());
	cout << s;
	return 0;
}
