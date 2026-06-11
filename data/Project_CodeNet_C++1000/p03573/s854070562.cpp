#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[3];
	cin>>a[1]>>a[2]>>a[3];
	sort(a+1,a+4);
	if(a[1]==a[2]) cout<<a[3];
	else cout<<a[1];
	cout<<endl;
	return 0;
 } 