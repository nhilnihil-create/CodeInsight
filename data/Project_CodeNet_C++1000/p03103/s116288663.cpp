#include<bits/stdc++.h>
using namespace std;
int d[100009];
int main()
{
	long long n,k,an=0;
	cin>>n>>k;
	pair<long long ,long long>a[n];
	for(int i=0;i<n;i++)cin>>a[i].first>>a[i].second;
	sort(a,a+n);
	for(auto i: a)
	{
		an+=i.first*max(0ll,min(k,i.second));
		k
		-=i.second;
		
	}
	cout<<an<<endl;
}

