#include<iostream>
using namespace std;
#define int long long int
bool prime(int x)
{
	if(x==2||x==3||x==5)
	    return true;
	if(x%2==0||x%3==0||x%5==0)
	    return false;
	for(int i=7;i*i<=x;i++)
	{
		if(x%i==0)
		    return false;
	}
	return true;
}
int32_t main()
{
	int n;
	cin>>n;
	int j;
	for(j=7;j;j++)
	{
		if(prime(j)&&j%5==2)
		{
			cout<<j<<" ";
			n--;
			if(n==0)
			   break;
		}
	}
	cout<<endl;
}
