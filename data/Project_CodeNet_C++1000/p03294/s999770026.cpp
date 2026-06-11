#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n+1];
	long long s=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s+=a[i];
		s--;
	}
	cout<<s;
 } 