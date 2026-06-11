#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, d, x, k, sum=0;
	cin>>n;
	cin>>d>>x;
	while(n--)
	{
		cin>>k;
		sum+=(d-1)/k+1;
	}
	sum+=x;
	cout<<sum<<endl;
}