#include<bits/stdc++.h>
using namespace std;
long long n,k;
int main()
{
	cin>>n;
	while(n>0)
	{
		if(n%10==2)
			k++;
		n/=10;
	}
	cout<<k;
	return 0;
}
