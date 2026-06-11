#include<bits/stdc++.h>
#define MOD (long long)(1e9+7)
using namespace std;
int n;
pair<int,int> a[105],b[105];
int main()
{
	cin >> n;
	for(int i=0; i<n; i++) cin >> a[i].first >> a[i].second;
	for(int i=0; i<n; i++) cin >> b[i].first >> b[i].second;
	sort(a,a+n);
	sort(b,b+n);
	int ans=0,vis[105]={0};
	for(int i=0; i<n; i++)
	{
		int maxd=-1,id=-1;
		for(int j=0; j<n; j++)
			if(!vis[j] && b[i].first>a[j].first && b[i].second>a[j].second && a[j].second>maxd)
			{
				
				maxd=a[j].second; id=j;
			}
		if(id>=0) vis[id]=1,ans++;
	}
	cout << ans;
	return 0;
}
