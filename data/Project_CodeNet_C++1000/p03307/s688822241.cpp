#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	long long a;
	cin>>a;
	if(a&1)cout<<(a<<1);
	else cout<<a;
	return 0;
} 