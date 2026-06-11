#include<bits/stdc++.h>
using namespace std;
string s2="keyence",s3="";
int ans=0,ans2=0;
int main()
{
	string s;
	cin>>s;
	int cha=s.size()-7;
	if(s==s2)
	{
		cout<<"YES"<<endl;
		return 0;
	}
	for(int i=0;i<7;i++)
	{
		s3="";
		for(int c=0;c<i;c++)
			s3+=s[c];
		for(int c=i+cha;c<s.size();c++)
			s3+=s[c];
		if(s3==s2)
		{
			cout<<"YES"<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;
	return 0;
}