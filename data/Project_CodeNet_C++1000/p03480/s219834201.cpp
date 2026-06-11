#include<bits/stdc++.h>
using namespace std;
int ans=1<<30;
int main()
{
	string s;
	cin>>s;
	int l=s.length();
	for(int i=1;i<l;i++)
	{
		if(s[i]!=s[i-1])
		{
			ans=min(ans,max(i,l-i));
		}
	}
	printf("%d",min(ans,l));
	return 0;
}