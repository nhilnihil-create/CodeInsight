#include<iostream>
#include<algorithm>
using namespace std;
#include<cmath>
#define int long long int
int32_t main()
{
	int d,n;
	cin>>d>>n;
	int answer=pow(100,d);
	answer*=n;
	if(n==100)
	{
		answer/=100;
		answer*=101;
		cout<<answer<<endl;
		exit(0);
	}
	cout<<answer<<endl;
}
