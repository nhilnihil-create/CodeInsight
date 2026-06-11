#include<iostream>
#include<algorithm>
using namespace std;
string s1,s2;
int main()
{
	cin>>s1>>s2;
	if(s1==s2)
	{
		cout<<"Yes";
		return 0;
	}
	int l=s1.length();
	int x=l-1;
	while(x!=0)
	{
		int x1=0;
		while(x1!=l-1)
		{
			if(s1[(x1+x)%l]==s2[x1])
			{
				x1++;
			}
			else
			{
				break;
			}
		}
		if(x1==l-1)
		{
			cout<<"Yes";
			return 0;
		}
		x--;
	}
	cout<<"No";
	return 0;
}