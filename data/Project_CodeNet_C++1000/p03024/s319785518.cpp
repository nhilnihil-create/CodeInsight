#include <iostream>

using namespace std;

int main()
{
	string str;
	int count = 0;
	int index = 0;

	cin >> str;
	while (str[index])
		if (str[index++] == 'x')
			++count;

	str = (count > 7) ? "NO" : "YES";
	cout << str << endl;
}