#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
using namespace std;
using P = pair<int,int>;
typedef long long ll;

int  main()
{

	int n; cin >> n;
	int cnt = 0;
	string s[n];
	queue<string> aq;
	queue<string> bq;
	string bxa;
	string ab;
	string str;

	rep(i, n)
	{
		cin >> s[i];
		if (s[i].front() == 'B' && s[i].back() == 'A')
		{
			bxa += s[i];
		}
		else if (s[i].front() == 'B')
		{
			bq.push(s[i]);
		}
		else if (s[i].back() == 'A')
		{
			aq.push(s[i]);
		}
		else
			str += s[i];
	}
	if (bq.size() == aq.size())
	{
		if (!bq.empty() && !aq.empty())
		{
			bxa = aq.front() += bxa;
			bxa += bq.front();
			aq.pop(); bq.pop();
		}
	}
	while (!aq.empty() && !bq.empty())
	{
		ab += (aq.front()+bq.front());
		aq.pop(); bq.pop();
	}
	if (!aq.empty())
	{
		while (!aq.empty())
		{
			bxa = aq.front() += bxa;
			aq.pop();
		}
	}
	if (!bq.empty())
	{
		while (!bq.empty())
		{
			bxa += bq.front();
			bq.pop();
		}
	}

	string ans = bxa + ab + str;
	rep(i, ans.size())
	{
		if (ans.substr(i, 2) == "AB")
			cnt++;
	}
	cout << cnt << endl;
	return (0);
}
