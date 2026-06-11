#include <bits/stdc++.h>
#define N 100010
using namespace std;
int main(){ 
	int n,a[N],i,j,ansa,ansb; 
	cin>>n;
	for(i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	ansa=a[n-1];
	for(i=n-2;i>=0;i--)
	{
		if(!i)
			ansb=a[i];
		if(min(a[i],a[n-1]-a[i])>=min(a[i-1],a[n-1]-a[i-1]))
		{
			ansb=a[i];
			break;
		}
	}
	cout<<ansa<<" "<<ansb<<endl;
	return 0;
}