#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,L[1<<17],R[1<<17];
vector<int>Left,Right;
long ans=0;
main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>L[i]>>R[i];
		Left.push_back(-R[i]*2);
		Right.push_back(L[i]*2);
	}
	sort(Left.begin(),Left.end(),greater<int>());
	sort(Right.begin(),Right.end(),greater<int>());
	long sum=0;
	for(int i=0;i<n;i++)
	{
		ans=max(ans,sum+Left[i]);
		ans=max(ans,sum+Right[i]);
		sum+=Left[i]+Right[i];
		ans=max(ans,sum);
	}
	cout<<ans<<endl;
}
