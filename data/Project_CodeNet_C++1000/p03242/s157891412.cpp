#include<iostream>
using namespace std;
int main()
{
	char c[5];
	cin>>c;
	for(int i=0;i<3;i++)
	{
		if(c[i]=='1') cout<<9;
		else if(c[i]=='9') cout<<1;
		else cout<<c[i];
	}
 } 