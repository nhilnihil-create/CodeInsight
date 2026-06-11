#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n,a,b;
	cin>>n>>a>>b;
	int ans[3]={},p;
	for (int i = 0; i < n; ++i)
	{
		cin>>p;
		if (p<=a)
		{
			++ans[0];
		}
		else if (p>=b+1)
		{
			++ans[2];
		}
		else
		{
			++ans[1];
		}
	}
	cout<<min({ans[0],ans[1],ans[2]})<<endl;
	return 0;
}
