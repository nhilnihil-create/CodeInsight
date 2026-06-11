#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll a[100005],b[100005];
priority_queue<ll>pq;
ll sum_minus=0,sum_plus=0;
int ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	cin >>a[i];
	for(int i=1;i<=n;i++)
	cin >>b[i];
	for(int i=1;i<=n;i++)
	{
		if(a[i]<b[i])
		{
			sum_minus+=b[i]-a[i];
			ans++;
		}
		else if(a[i]>b[i])
		{
			sum_plus+=a[i]-b[i];
			pq.push(a[i]-b[i]);
		}
	}
	if(sum_minus>sum_plus)
	{
		puts("-1");
		return 0;
	}
	if(sum_minus==0)
	{
		puts("0");
		return 0;
	}
	while(!pq.empty())
	{
		ll x=pq.top();
		pq.pop();
		sum_minus-=x;
		ans++;
		if(sum_minus<=0)
		{
			cout <<ans<<endl;
			return 0;
		}
	}
}