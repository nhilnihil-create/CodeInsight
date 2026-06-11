#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int		main(void)
{
	int		a, b, cnt;
	cnt = 0;
	cin >> a >> b;
	vector<vector<bool>> A(a, vector<bool> (b, false));
	cin >> a >> b;
	for (int i = 0; i < a; i++)
	{
		for (auto &&j : A.at(i))
			j = true;
	}
	// printf("--現在の行数は{%d}行目です。--\n", __LINE__);
	for (int i = 0; i < b; i++)
	{
		for (int j = 0; j < A.size(); j++)
			A.at(j).at(i) = true;
	}
	// printf("--現在の行数は{%d}行目です。--\n", __LINE__);
	for (int i = 0; i < A.size(); i++)
	{
		for (auto &&j : A.at(i))
		{
			if (j == false)
				cnt++;
		}
	}
	cout << cnt << endl;
}