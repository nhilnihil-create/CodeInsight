#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	string s;
	int n,k;
	cin >> n >> k;
	cin >> s;
	s[k-1] = 'a' - 'A' + s[k-1];
	cout << s << endl;
}
