#include <bits/stdc++.h>
#define N 200010
#define INF 1000000010
using namespace std;
pair<long long,long long> gl[N],gr[N];
long long a[N];
int main(){
	int n,i,now=0;
	long long sl=0,sr=0,ans=INF;
	vector<long long> v;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>a[i];
	for(i=0;i<n;i++)
	{
		sr+=a[i];
		while(now<=i&&abs(sl-sr)>=abs(sl+a[now]-(sr-a[now])))
		{
			sl+=a[now];
			sr-=a[now];
			now++;
		}
		gl[i]=make_pair(sl,sr);
	}
	sl=0;
	sr=0;
	now=n-1;
	for(i=now;i>=0;i--)
	{
		sl+=a[i];
		while(now>=i&&abs(sl-sr)>=abs(sl-a[now]-(sr+a[now])))
		{
			sl-=a[now];
			sr+=a[now];
			now--;
		}
		gr[i]=make_pair(sl,sr);
	}
	for(i=1;i<=n-1;i++)
	{
		v.clear();
		v.push_back(gl[i].first);
		v.push_back(gl[i].second);
		v.push_back(gr[i+1].first);
		v.push_back(gr[i+1].second);
		sort(v.begin(),v.end());
		ans=min(ans,v[3]-v[0]);
	}
	cout<<ans<<endl;
	return 0;
}