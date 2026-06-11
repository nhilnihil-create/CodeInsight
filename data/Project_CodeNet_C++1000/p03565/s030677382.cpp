#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#define PRE std::ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
const int Max = 1e6 + 5;
const int Mod = 1e9 + 7;
int lst[Max], f[Max];
int ls[Max];

int main()
{
	PRE;
	string str, st;
	cin >> str >> st;
	int n = st.size(), k = -1;
	for (int i = str.size() - n;i >= 0;i--)
	{
		int f = 1;int g = -1;
		for (int j = i;j < i + n;j++)
		{
			++g;
			if (!(str[j] == '?' || str[j] == st[g])) f = 0;
		}
		if (f)
		{
			k = i;break;
		}
	}
	if (k == -1)cout << "UNRESTORABLE";
	else
	{
		for (int i = 0;i <= k - 1;i++)
		{
			if (str[i] == '?')cout << 'a';
			else cout << str[i];
		}
		cout << st;
		for(int i=k+n;i<str.size();i++)
		{
			if (str[i] == '?')cout << 'a';
			else cout << str[i];
		}
	}
}