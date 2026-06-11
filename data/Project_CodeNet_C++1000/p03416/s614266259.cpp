/*https://atcoder.jp/contests/abc090/tasks/abc090_b*/
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
	int l, r, count = 0;
	cin >> l >> r;

	for (int i = l; i <=r; i++)
	{
		int x = i;
		string s = to_string(x);
		if (s[0] == s[4] && s[1] == s[3])
			count++;
	}
	cout << count;
}