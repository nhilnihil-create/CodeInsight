#include<bits/stdc++.h>
using namespace std;
int main()
{
	int i=0;
	string s,e="keyence";
	cin>>s;
	for(int t=0;t<s.size();t++)
	{
		if(s[t]!=e[i])
		{
			s.erase(t,s.size()-7);
			break;
		}
		else
		{
			i++;
		}
	}
	if(s==e)
	{
		cout<<"YES";
	}
	else
	{
		cout<<"NO";
	}
	return 0;
}