#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(int n)
{
	auto s = to_string(n);
	return s == string(s.rbegin(), s.rend());
}
int main()
{
	int a, b;
	cin >> a >> b;
	int c = 0;
	for (int i = a; i <= b; i++)
		if (isPalindrome(i))
			c++;
	cout << c << endl;
}
