#include <bits/stdc++.h>

using namespace std;

#define  input freopen("in.txt","r",stdin)
#define  output freopen("out.txt","w",stdout)

int main()
{
	//input;
	//output;

	string s;
	cin >> s;
	int n = s.size();
	s = "#"+s;

	if(s[1]!='1' || s[n]!='0')
	{
		cout << -1 << '\n';
		return 0;
	}
	for(int i = 1; i < n; i++)
	{
		if(s[i]!=s[n-i])
		{
			cout << -1 << '\n';
			return 0;
		}
	}
	s[n] = '1';
	queue<int>q;
	for(int i = 1; i <= n; i++)
		if(s[i]=='1') q.push(i);

	for(int i = 1; i < n; i++)
	{
		if(i==q.front()) q.pop();
		cout << i << ' ' << q.front() << '\n';
	}
	return 0;
}