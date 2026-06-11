#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define INF 1000000007
using namespace std;

int n,a[200010],cnt;
pair<int,int> q[200010];

inline bool check(int x)
{
	if(x==1){
		bool flag=false;
		for(int i=1;i<n;i++) if(a[i]>=a[i+1]){
			flag=true;
			break;
		}
		if(!flag) return true;
		return false;
	}
	int pre=0;
	map<int,int> mp;
	mp.clear();
	for(int i=1;i<=n;i++){
		if(a[i]<=pre){
			pre=a[i];
			while(pre>=1){
				if(mp[pre]+1<x) break;
				mp[pre]=0;
				pre--;
			}
			if(pre==0) return false;
			mp[pre]++;
		}
		else pre=a[i];
		mp.erase(mp.upper_bound(pre),mp.end());
	}
	return true;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	int l=1,r=INF,ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)){
			ans=mid;
			r=mid-1;	
		}
		else l=mid+1;
	}
	cout<<ans<<endl; 
	return 0;
}