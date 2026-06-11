#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int main()
{
	string s;
	int w;
	cin>>s;
	scanf("%d",&w);
	int l=s.size();
	for(int i=0;i<l;i+=w)
	{
		cout<<s[i];
	}
	return 0;
}