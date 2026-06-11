#include <stdio.h>
#include <set>
#include <string>
#include <iostream>
using namespace std;
int main()
{
	string s;
	cin>>s;
	set<string> skup;
	for(int i=0;i<s.size();i++)
	{
		for(int j=1;j<=5 && i+j<=s.size();j++)
		{
			skup.insert(s.substr(i,j));
		}
	}
	int k;
	scanf("%i",&k);
	string res;
	for(int i=1;i<=k;i++)
	{
		res=*skup.begin();
		skup.erase(skup.begin());
	}
	cout<<res;
	return 0;
}
