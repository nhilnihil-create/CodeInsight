#include<bits/stdc++.h>
using namespace std;
int main()
{	int a,b;
	cin>>a>>b;
	a%=2;
	b%=2;
	if(a==1&&b==1)cout<<"Odd";
	else if(a==2&&b==2)cout<<"Even";
	else cout<<"Even";
	return 0;
}
