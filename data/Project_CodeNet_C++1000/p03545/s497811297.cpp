#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
#include<map>
#define PRE std::ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
const int Max = 1e6 + 5;
const int Mod = 1e9 + 7;
char lst[4], sec[2] = { '+','-' };

int main()
{
	PRE;
	string str;cin >> str;

	int a=str[0]-'0', b=str[1]-'0', c=str[2]-'0', d=str[3]-'0';
	char c1, c2, c3;
	int ans = a;
	for (int i = 0;i <= 1;i++)
	{
		if (sec[i] == '+') ans += b;
		else ans -= b;
		for (int j = 0;j <= 1;j++)
		{
			if (sec[j] == '+')ans += c;
			else ans -= c;
			for (int k = 0;k <= 1;k++)
			{
				if (sec[k] == '+')ans += d;
				else ans -= d;
				if (ans == 7)
				{
					c1 = sec[i];c2 = sec[j];c3 = sec[k];
					cout << a << c1 << b << c2 << c << c3 << d << "=" << 7;
					return 0;
				}
				if (sec[k] == '+')ans -= d;
				else ans += d;
			}
			if (sec[j] == '+')ans -= c;
			else ans += c;
		}
		if (sec[i] == '+')ans -= b;
		else ans += b;
	}
}