#include <iostream>
using namespace std;

int main()
{
	string s;
	cin >> s;
	int k = s.size();
	for (int i = 0; i < k; ++i)
	{
		cin >> s[i];
	}
	int a = 0;
	for (int i = 0; i < k; ++i)
	{
		if (s[i] == 'o')
		{ 
			a = a+1;
		}
	}
	if (a+(15-k) > 7)
		cout << "YES";
	else
		cout << "NO";
}