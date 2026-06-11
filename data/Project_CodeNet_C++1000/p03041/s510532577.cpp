#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	int n, k;
	cin >> n >> k >> s;
	s[k - 1] = (char)((int)s[k - 1] + 32);
	cout << s;
	return 0;
}
