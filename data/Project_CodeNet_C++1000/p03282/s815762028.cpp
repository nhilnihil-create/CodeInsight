#include<iostream>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int k;
	cin>>k;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]!='1')
		{
			cout<<s[i];
			return 0;
		}
		else if(i==k-1)
		{
			cout<<1;
			return 0;
		}
	}
	return 0;
}