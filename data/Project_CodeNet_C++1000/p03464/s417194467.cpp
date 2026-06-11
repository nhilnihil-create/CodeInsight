#include<bits/stdc++.h>
using namespace std;
long long l=2,r=2,n,ans[100005];
int main()
{
	cin>>n;
	for(int i=1; i<=n; i++)cin>>ans[i];
	for(int i=n; i>=1; i--)l=((l-1)/ans[i]+1)*ans[i],r=r/ans[i]*ans[i]+ans[i]-1;
	if(l>r)cout<<-1;else cout<<l<<" "<<r;
	return 0;
}