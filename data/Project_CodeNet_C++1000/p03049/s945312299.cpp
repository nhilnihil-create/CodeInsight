#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
using namespace std;
using P = pair<int,int>;
typedef long long ll;

template<class T, class U>
bool contain(const std::basic_string<T>& s, const U& v)
{
	return s.find(v) != std::basic_string<T>::npos;
}
// int ans = contain(s, "AB");

int  main()
{

	int n; cin >> n;
	int cnt = 0;
	string s[n];
	queue<string> aq;
	queue<string> bq;
	string abq;
	string ab;
	string str;
	int k = 0 , b = 0, z = 0;
	rep(i, n)
	{
		cin >> s[i];
		if (s[i].front() == 'B' && s[i].back() == 'A')
		{
			abq += s[i];
			k++;
		}
		else if (s[i].front() == 'B')
		{
			bq.push(s[i]);
			b++;
		}
		else if (s[i].back() == 'A')
		{
			aq.push(s[i]);
			z++;
		}
		else
			str += s[i];
	}
	if (b == z)
	{
		if (!bq.empty() && !aq.empty())
		{
			abq = aq.front() += abq;
			abq += bq.front();
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
			abq = aq.front() += abq;
			aq.pop();
		}
	}
	if (!bq.empty())
	{
		while (!bq.empty())
		{
			abq += bq.front();
			bq.pop();
		}
	}
	string ans = abq + ab + str;
	rep(i, ans.size())
	{
		if (ans.substr(i, 2) == "AB")
			cnt++;
	}
	// cout << k << endl;
	// cout << b << endl;
	// cout << z << endl;
	cout << cnt << endl;
	return (0);
}
