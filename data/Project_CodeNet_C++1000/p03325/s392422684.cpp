#include<iostream>
#include<algorithm>
using namespace std;
#define int long long int
int32_t main()
{
	int n;
	cin>>n;
	int answer=0;
	int j;
	for(j=0;j<n;j++)
	{
		int x;
		cin>>x;
		while(x%2==0)
		{
			answer++;
			x/=2;
		}
	}
	cout<<answer<<endl;
}
