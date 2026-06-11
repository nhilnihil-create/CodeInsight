#include<iostream>
#include<cmath>//1000000000000
using namespace std;
int main()
{
	long long N,k=0;
	cin>>N;
	double n=sqrt(N);
	for(long long i=1;i<n;i++)
		if(N%i==0)
		{
			if((i+1)<N/i)
				k+=N/i-1;
		}
		cout<<k;
		return 0;
}