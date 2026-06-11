#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;
	if(n%m==0)
	{
		cout<<0<<endl;
		return 0;
	}
	if(n%m!=0||n<m)
	{
		cout<<1<<endl;
		return 0;
	}
 } 
