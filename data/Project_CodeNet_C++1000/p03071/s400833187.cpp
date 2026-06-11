#include<bits/stdc++.h>
int main()
{
	int a,b;
	std::cin>>a>>b;
	if(a>b)
	std::cout<<(a*2)-1<<"\n";
	else if(a==b)
	std::cout<<a+b<<"\n";
	else
	std::cout<<(b*2)-1<<"\n";
}