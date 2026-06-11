#include<bits/stdc++.h>
using namespace std;
int main()
{
	long int n,i,sum=0,array[10001];
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>array[i];
		sum=sum+array[i];
	}
	sort(array,array+n);
	cout<<sum-(array[n-1]/2)<<endl;
	
	return 0;
}