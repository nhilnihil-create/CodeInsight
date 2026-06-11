#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	string s;
	cin >> s;
	string t = s;
	int n = s.size();
	if(s.size()==26)
	{
		if(next_permutation(s.begin(),s.end()))
		{
			for(int i = 0;i<n;i++)
			{
				if(s[i]==t[i])cout<<t[i];
				else
				{
					cout<<s[i];
					cout<<endl;
					return 0;
				}
			}
		}
		else
		{
			cout<<-1<<endl;
		}
	}
	else
	{
		vector<bool> v(26);
		for(auto c:s)v[c-'a']=true;
		cout<<s;
		for(int i = 0;i<26;i++)
		{
			if(v[i]==false)
			{
				cout<<(char)('a'+i)<<endl;
				return 0;
			}
		}
	}
	
	return 0;
}