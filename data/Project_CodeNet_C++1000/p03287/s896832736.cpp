#include<iostream>
using namespace std;
#include<map>
#define int long long int
int32_t main()
{
	int n,m;
	cin>>n>>m;
	int j,arr[n+1]={0};
	for(j=1;j<=n;j++)
	   cin>>arr[j];
	int prefix[n+1]={0};
	for(j=1;j<=n;j++)
	{
		prefix[j]=(arr[j]+prefix[j-1])%m;
	}
	int answer=0;
	map<int,int> mp;
	for(j=n;j>=1;j--)
	{
		mp[prefix[j]]++;
		answer+=mp[prefix[j-1]];
	}
	cout<<answer<<endl;
}
