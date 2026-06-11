#include<iostream>
using namespace std;
int main()
{
	int N,n;
	cin>>N;
	if(N>=1&&N<=1000)
	{
		if(N>=3)
		{
			n=N/3;
		}
		else
		{
			n=0;
		}
	}
	cout<<n;
}