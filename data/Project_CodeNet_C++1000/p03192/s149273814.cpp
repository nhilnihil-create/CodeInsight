#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	cin >> str;
	int ans = 0;
	for (const auto& c : str)
		if (c == '2')
			ans++;
	cout << ans << endl;
	return 0;
}