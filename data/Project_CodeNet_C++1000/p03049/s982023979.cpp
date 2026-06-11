#include<iostream>
#include<algorithm>
using namespace std;
int N,a,b,c;
long ans;
main()
{
	cin>>N;
	for(int i=0;i<N;i++)
	{
		string s;cin>>s;
		for(int j=0;j+1<s.size();j++)
		{
			if(s[j]=='A'&&s[j+1]=='B')ans++;
		}
		if(s[0]=='B'&&s[s.size()-1]=='A')c++;
		else if(s[0]=='B')b++;
		else if(s[s.size()-1]=='A')a++;
	}
	if(a>0&&b>0)
	{
		ans+=c+1;
		c=0;
		a--,b--;
		ans+=min(a,b);
	}
	else if(a>0)
	{
		ans+=c;
	}
	else if(b>0)
	{
		ans+=c;
	}
	else
	{
		if(c>0)ans+=c-1;
	}
	cout<<ans<<endl;
}
