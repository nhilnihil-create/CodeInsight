#include<iostream>
#include<string>
#include<iomanip>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{	
	int n,mx=0; cin >> n;
	string s; cin >> s;
	for (int i = 1; i < n; ++i)
	{
		int c = 0;
		string s1 = s.substr(0, i);
		string s2 = s.substr(i, n - i);
		vector<int>a(26);
		vector<int>b(26);
		for (int h = 0; h < s1.size(); ++h)
			a[s1[h] - 'a']++;
		for (int h = 0; h < s2.size(); ++h)
			b[s2[h] - 'a']++;
		for (int h = 0; h < 26; ++h)
			if (a[h] > 0 && b[h] > 0)
				c++;
		mx = max(c, mx);
	}
	cout << mx;







}