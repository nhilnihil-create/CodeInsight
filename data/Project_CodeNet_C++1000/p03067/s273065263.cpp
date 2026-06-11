//https://atcoder.jp/contests/tenka1-2019-beginner/tasks/tenka1_2019_a
#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(void)
{
	int A, B, C;

	cin >> A;
	cin >> B;
	cin >> C;

	int pos = A - B >= 0;

	if (pos)
	{
		if (C < A && C > B)
		{
			cout << "Yes";
		}
		else
		{
			cout << "No";
		}
	}
	else
	{
		if (C > A && C < B)
		{
			cout << "Yes";
		}
		else
		{
			cout << "No";
		}
	}




}