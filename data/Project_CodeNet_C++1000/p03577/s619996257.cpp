#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
std::string a;int t=0;
int main()
{
	std::cin>>a;
	for(int t=0;t<a.size()-8;t++)
	{
		printf("%c",a[t]);
	}
}