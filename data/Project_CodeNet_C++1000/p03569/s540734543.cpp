#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	string s;
	string t1,t2;

	cin >> s;

	for(int i=0;i<s.length();i++)
	{
		if(s[i]!='x')
		{
			t1 += s[i];
		}
	}

	t2 = t1;

	reverse(t2.begin(),t2.end());

	if(t2!=t1)
	{
		cout << -1 << '\n';
		return 0;
	}

	vector <int> v;
	int cnt = 0;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]!='x')
		{
			v.push_back(cnt);
			cnt = 0;
		}
		else
		{
			cnt++;
		}
	}
	v.push_back(cnt);
	//cout << v.size() << '\n';
	int m = v.size();
	int res = 0;
	for(int i=0;i<(m/2);i++)
	{
		res += abs(v[i] - v[m-1-i]);
	}

	cout << res << '\n';
	return 0;
}