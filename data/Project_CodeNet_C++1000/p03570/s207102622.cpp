#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n,i,j,f[(1<<26)+5],ans,c[212345];
string s;
int main()
{
	cin>>s;
	s=" "+s;
	n=s.size();
	for (i=1;i<n;i++)
	{
		c[i]=c[i-1]^(1<<(s[i]-'a'));
	}
	if (!c[n-1]){cout<<"1\n";return 0;}
	memset(f,50,sizeof(f));
	f[0]=0;
	for (i=1;i<n;i++)
	{
		ans=n+n+n+n+345;
		for (j=0;j<26;j++)
		{
			ans=min(ans,f[c[i]^(1<<j)]+1);
		}
		f[c[i]]=min(f[c[i]],ans);
	}
	cout<<f[c[n-1]]<<endl;
	return 0;
}