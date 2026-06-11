#include <bits/stdc++.h>
using namespace std;
map <pair<string, string>, int> m;
int b;
string t;
bool td[36];
long long u = 0;
string s(bool s, int k)
{
	string ts = "";
	if(s == 0)
	{
		for(int i = k-b; i < k; i++)
		{
			if(td[i] == 1)
			{
				ts += t[i];
			}
		}
	}
	else
	{
		for(int i = k-1; i >= k-b; i--)
		{
			if(td[i] == 0)
			{
				ts += t[i];
			}
		}
	}
	return ts;
}
void f(int p, int k)
{
	if(p == k)
	{
		if(k == b)
		{
			m[make_pair(s(1, k), s(0, k))]++;
		}
		else
		{
			u += m[make_pair(s(0, k), s(1, k))];
		}
		return;
	}
	f(p+1, k);
	td[p] = 1;
	f(p+1, k);
	td[p] = 0;
}
int main()
{
    cin >> b;
    cin >> t;
    f(0, b);
    f(b, 2*b);
    cout << u <<endl;
}

