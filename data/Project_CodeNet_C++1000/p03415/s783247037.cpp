#include <iostream>
#include <string>
#include <array>
using namespace std;

int main()
{
	array<string, 3> s;
	for (auto& i : s) {
		cin >> i;
	}
	cout << s[0][0] << s[1][1] << s[2][2] << endl;
	return 0;
}
