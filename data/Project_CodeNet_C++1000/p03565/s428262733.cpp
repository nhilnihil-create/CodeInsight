#include <bits/stdc++.h>
using namespace std;

int n,m,flag=0,pos;
char s[55],pre[55];

int main()
{
	string s1,s2;
	cin>>s1>>s2;
	n=s1.size(),m=s2.size();
	for (int i=1;i<=n;i++)  s[i]=s1[i-1];
	for (int i=1;i<=m;i++)  pre[i]=s2[i-1];
	
	for (int i=n-m+1;i>=1;i--)
	{
		bool dog=1; 
		for (int j=i;j<=i+m-1;j++)
		{
			if (s[j]!=pre[j-i+1]&&s[j]!='?')
			{
				dog=0;
				break;
			}
		}
		if (dog==1)
		{
			flag=1;
			pos=i;
			break;
		}
	}
	if (flag==0)
	{
		cout<<"UNRESTORABLE"<<endl;
		return 0;
	}
	for (int i=pos;i<=pos+m-1;i++)  s[i]=pre[i-pos+1];
	for (int i=1;i<=n;i++)
	{
		if (s[i]=='?')  s[i]='a';
	}
	for (int i=1;i<=n;i++)  cout<<s[i];
	cout<<endl;
	return 0;
}