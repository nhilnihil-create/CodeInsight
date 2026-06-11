#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int a[3];
	for (int i = 0; i < 3; ++i)
	{
		cin>>a[i];
	}
	sort(a,a+3);
	if (a[0]==a[2])
	{
		cout<<"Yes\n";
	}
	else
	{
		cout<<"No\n";
	}
	return 0;
}
