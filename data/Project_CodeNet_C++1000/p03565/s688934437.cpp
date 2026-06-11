#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> vec;
	string s, t,ss, ans;
	bool tf;
	cin >> s >> t;
	ans = "UNRESTORABLE";
	int n, m, count, p,q;

	p = -1;
	q = 0;
	n = s.size();
	m = t.size();
	for (int i = n-m; 0<=i; i--)
	{
		count = 0;
		ss = s.substr(i, m);
		for (int x = 0; x < m; x++)
		{
		
			if (ss[x] == '?' || ss[x] == t[x])
			{
				count++;
			}
		}
		if(count==m)
		{
			vec.push_back(i);
			q++;
		}
	}
	

	if (0<q)
	{
		p = vec[0];
		ans = s;
		ans.erase(p, m);
		ans.insert(p, t);
		for (int i = 0; i < n; i++)
		{
			if (ans[i] == '?')
			{
				ans[i] = 'a';
			}
		}
	}

	cout << ans;



	return 0;
}