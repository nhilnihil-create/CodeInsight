#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a[9],n=3;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	a[2]*=10;
	cout<<a[0]+a[1]+a[2]<<endl;
	return 0;
}