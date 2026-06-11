#include<iostream>
#include<cmath>
#include<string>
using namespace std;
int main() {
	string s; cin >> s;
	int a = 0, b = 0, c = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'a')a++;
		else if (s[i] == 'b')b++;
		else c++;
	}
	cout << ((abs(a - b) <= 1 && abs(b - c) <= 1 && abs(c - a) <= 1) ? "YES\n" : "NO\n");
}