#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
using namespace std;
using P = pair<int,int>;
typedef long long ll;

int  main()
{
	int n; cin >> n;
	string s; cin >> s;
	priority_queue<int> que;
	rep(i, n)
	{
		string l; string r;
		l = s.substr(0, i + 1);
		r = s.substr(i + 1, (n - 1) - i);
		int cnt = 0;
		for (char a = 'a'; a <= 'z'; a++)
		{
			if (count(l.cbegin(), l.cend(), a) && count(r.cbegin(), r.cend(), a))
				cnt++;
		}
		que.push(cnt);
	}
	cout << que.top() << endl;
	return (0);
}
