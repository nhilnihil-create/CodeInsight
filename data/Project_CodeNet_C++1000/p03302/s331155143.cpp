#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int a,b;
	cin>>a>>b;
	if (a+b==15)
	{
		cout<<"+\n";
	}
	else if (a*b==15)
	{
		cout<<"*\n";
	}
	else
	{
		cout<<"x\n";
	}
	return 0;
}
