/*https://atcoder.jp/contests/abc122/tasks/abc122_b*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	string s;
	int count = 0, max_count = 0;
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == 'A' || s[i] == 'G' || s[i] == 'C' || s[i] == 'T')
			count++, max_count = max(max_count, count);
		else
			count = 0;
	}
	cout << max_count;
}