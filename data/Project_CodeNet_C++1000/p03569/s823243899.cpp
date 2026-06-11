#include<iostream>
using namespace std;
string s;
main()
{
	cin>>s;
	long ans=0;
	int j=0,now=0;
	for(int i=0;i<s.size()-j;i++)
	{
		if(s[i]=='x')
		{
			now++;
			continue;
		}
		for(;s[s.size()-j-1]!=s[i];j++)
		{
			now--;
			if(s[s.size()-j-1]!='x')
			{
				cout<<-1<<endl;
				return 0;
			}
		}
		j++;
		ans+=now>0?now:-now;
		now=0;
	}
	cout<<ans<<endl;
}
