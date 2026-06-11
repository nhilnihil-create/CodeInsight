#include <bits/stdc++.h>
using namespace std;

int main() {
	int s,s1,s2,s3;
	cin >> s;
	s3 = s % 10;
	s2 = s / 10 % 10;
	s1 = s / 100;
	cout << s1+s2+s3 << endl;
}
