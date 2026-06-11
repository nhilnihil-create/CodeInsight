#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(void) {

	int k;

	string s;

	cin >> s;

	s.erase(s.end()-8, s.end());

	cout << s << "\n";

	return 0;
}