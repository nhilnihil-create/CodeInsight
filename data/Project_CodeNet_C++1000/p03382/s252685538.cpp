#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,a[N];
int binary_search(int num)
{
	int low=0,high=n-1;
	while(low<high-1)
	{
		int mid=(low+high)>>1;
		if(a[mid]<num)
			low=mid;
		else
			high=mid;
	}
	if(high==n-1)return a[low];
	if(low==n-1)return a[high];
	if(abs(a[low]-num)<abs(a[high]-num))
		return a[low];
	else
		return a[high];
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	cout<<a[n-1]<<' '<<binary_search(a[n-1]/2);
	return 0;
}