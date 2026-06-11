/*https://atcoder.jp/contests/abc124/tasks/abc124_c*/
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
	string s1, s2;
	int count = 0, flag = 1;
	cin >> s1;
	if (s1[0] == '0')
		s2 += '0', flag = 0;
	else if (s1[0] == '1')
		s2 += '1', flag = 1;
	for (int i = 1; i < s1.length(); i++)
	{
		if (flag == 0)
			s2 += '1', flag = 1;
		else if (flag == 1)
			s2 += '0', flag = 0;
	}
	for (int i = 0; i < s2.length(); i++)
	{
		if (s1[i] != s2[i])
			count++;
	}
	cout << count;
}