#include<iostream>
#include<cstdio>
#include<queue>
#include<string>
#include<stack>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;
string s; 
int main()
{
	cin>>s;
	int ans=s.length();
	int l=s.length();
	for(int i=1;i<l;i++)
	{
		if(s[i]!=s[i-1])
		{
			ans=min(ans,max(i,l-i));
		}
	}
	cout<<ans;
	return 0;
}
