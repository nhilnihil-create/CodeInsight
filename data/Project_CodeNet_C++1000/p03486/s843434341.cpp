#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;
const int Max = 1e3 + 7;
int ls1[Max], ls2[Max];
int n;


int main()
{
	string s, t;
	cin >> s >> t;
	for (int i = 0; i <= s.size() - 1; i++)
	{
		ls1[i] = s[i] - 'a' + 1;
	}
	for (int i = 0; i <= t.size() - 1; i++)
	{
		ls2[i] = t[i] - 'a' + 1;
	}
	sort(ls1, ls1 + s.size());
	sort(ls2, ls2 + t.size(),greater<int>());
	int f =0;
	for (int i = 0; i <= max(s.size(), t.size()) - 1; i++)
	{
		if (ls1[i] == ls2[i])continue;
		if (ls1[i] < ls2[i])
		{
			f = 1;
			break;
		}
		else
		{
			f = 0;
			break;
		}
	}
	if (f)cout << "Yes";
	else cout << "No";
}