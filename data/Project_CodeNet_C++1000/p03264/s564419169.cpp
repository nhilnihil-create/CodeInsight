#include<iostream>
using namespace std;
int main()
{
	int k,o,j;
	cin>>k;
	o=0;
	j=0;
	for(int i=1;i<=k;i++)
	{
		if(i%2==0)
		o++;
		else if(i%2==1)
		j++;
	}
	cout<<o*j<<endl;
 } 