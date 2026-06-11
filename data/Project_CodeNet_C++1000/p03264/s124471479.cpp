#include<iostream>
using namespace std;
int main()
{
	int k,sum=0;
	cin>>k;
	for(int i=1;i<=k;i++)
	{
		for(int j=i+1;j<=k;j+=2)
			sum++;
	}
	cout<<sum;
 } 