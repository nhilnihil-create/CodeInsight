#include<iostream>
#include<algorithm>
#define ios ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
int arr[106];
int main()
{
	ios;
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>arr[i];
	}
	sort(arr+1,arr+1+n);
	int sum=0,f=1;
	for(int i=n;i>=1;--i)
	{
		sum+=arr[i]*f;
		f*=-1;
	}
	cout<<sum<<'\n';
} 