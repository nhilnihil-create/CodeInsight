#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	string s;
	long long ans;
	deque<char> dq;

	cin >> s;
	rep(i, s.size())
	{
		dq.push_back(s[i]);
	}
	ans = 0;
	while(!(dq.size() <= 1))
	{
		char f = dq.front(); 
		char b = dq.back(); 
		if (f == b)
		{
			dq.pop_front();
			dq.pop_back();
		}
		else if (f == 'x') 
		{
			ans++;
			dq.push_back('x');
		}
		else if (b == 'x')
		{
			ans++;
			dq.push_front('x');
		}
		else if (f != 'x' && b != 'x')
		{
			ans = -1;
			break;
		}
	}
	cout << ans << endl;
	return 0;
}
