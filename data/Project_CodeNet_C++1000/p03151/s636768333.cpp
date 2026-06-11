#include<bits/stdc++.h>
using namespace std;
const long long maxn=1e5+5;
const long long inf=0x3f3f3f3f;
long long a[maxn],b[maxn],ans,sum1,sum2,sum,minu;
priority_queue<long long> q;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	long long n;
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		sum1+=a[i];
	}
	for(long long i=1;i<=n;i++)
	{
		cin>>b[i];
		sum2+=b[i];
	}
	if(sum1<sum2)
	{
		cout<<"-1"<<endl;
		return 0;
	}
	for(long long i=1;i<=n;i++)
	{
		if(a[i]>b[i])
		{
			minu+=a[i]-b[i];
			q.push(a[i]-b[i]);
		}
		if(a[i]<b[i])
		{
			sum+=b[i]-a[i];
			ans++;
		}
	}
	if(sum==0)
	{
		cout<<"0"<<endl;
		return 0;
	}
	while(!q.empty())
	{
		long long x=q.top();
		q.pop();
		sum-=x;
		ans++;
		if(sum<=0)
			break;
	}
	cout<<ans<<endl;
	return 0;
}


