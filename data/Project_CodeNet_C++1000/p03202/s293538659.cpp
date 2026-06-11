#include <bits/stdc++.h>
using namespace std;
int n,a[200005];
inline bool check(int x){
	if(x==1){
		bool flag=1;
		for(int i=1;i<n;i++)	if(a[i+1]<=a[i])	flag=0;
		return flag;
	}
	map<int,int> mp;
	int cur=0;
	for(register int i=1;i<=n;i++){
		if(a[i]<=cur){
			cur=a[i];
			while(1){
				if(mp[cur]<x-1)	break;
				mp[cur]=0;
				cur--;
			}
			mp[cur]++;
			if(cur<=0)	return 0;
		}
		else	cur=a[i];
		mp.erase(mp.upper_bound(cur),mp.end());
	}
	return 1;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)	cin>>a[i];
	int l=1,r=300000,ans;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid))	ans=mid,r=mid-1;
		else			l=mid+1;
	}
	cout<<ans<<endl;
	return 0;
}