#include<bits/stdc++.h>
#define mx(a,b) (a>b?a:b)
#define mn(a,b) (a<b?a:b)
using namespace std;
string s;int ans=1<<30; 
int main()
{
	cin>>s;
	for(int i=1;i<s.length();i++)
		if(s[i]!=s[i-1])
			ans=mn(ans,mx(i,int(s.length())-i));
	printf("%d\n",mn(ans,int(s.length())));
	return 0;
}