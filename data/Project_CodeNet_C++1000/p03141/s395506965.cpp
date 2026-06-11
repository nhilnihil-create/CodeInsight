#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n;
long a[1<<17],b[1<<17];
vector<pair<long,int> >A;
main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>b[i];
		A.push_back(make_pair(a[i]+b[i],i));
	}
	sort(A.begin(),A.end());
	reverse(A.begin(),A.end());
	long ans=0;
	for(int i=0;i<n;i++)
	{
		if(i%2)ans-=b[A[i].second];
		else ans+=a[A[i].second];
	}
	cout<<ans<<endl;
}
