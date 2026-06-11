#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;
	int count = 0;
	TRAVEL:
	for (int i = 0; i < (int)s.size() - 1; i++)
	{
		if (s[i] != s[i + 1])
		{
			s.erase(i, 2);
			count += 2;
			goto TRAVEL;
		}
	}
	cout << count;
}