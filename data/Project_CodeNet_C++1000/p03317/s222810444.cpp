#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,x, k, i;
	cin>>n>>k;
	for(i=0; i<n; i++)cin>>x;
	int ans=0;
	int r=1;
	while(r<n)
	{
		r+=(k-1);
		ans++;
	}
	cout<<ans<<endl;
}
