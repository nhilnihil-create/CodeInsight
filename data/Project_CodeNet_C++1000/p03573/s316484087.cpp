#include<bits/stdc++.h>
using namespace std;
int a[2];
int main()
{
	cin>>a[0]>>a[1]>>a[2];
	sort(a,a+3);
	if(a[0]!=a[1] && a[0]!=a[2]) cout<<a[0]<<endl;
	if(a[1]!=a[0] && a[1]!=a[2]) cout<<a[1]<<endl;
	if(a[2]!=a[0] && a[2]!=a[1]) cout<<a[2]<<endl;
	return 0;
}
