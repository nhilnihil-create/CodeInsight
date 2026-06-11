#include<bits/stdc++.h>
using namespace std;
int a[10],s=0;
int main()
{
	cin>>a[1]>>a[2]>>a[3];
	sort(a+1,a+4);
	while(a[1]!=a[2]||a[2]!=a[3])
	{
		if(a[2]==a[3])
		{
			a[1]=a[1]+2;
			s++;
		}
		else
		{
			a[2]++;
			a[1]++;
			s++;
		}
		sort(a+1,a+4);
	}
	cout<<s;
}