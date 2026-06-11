#include<iostream>
using namespace std;

int main() {
	string s; cin >> s;
	int add = 0; for (auto x : s)if (x == 'o')add += 100;
	cout << 700 + add << endl;

	return 0;
}