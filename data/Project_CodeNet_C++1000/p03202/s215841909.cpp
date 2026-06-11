#include<bits/stdc++.h>
using namespace std;
map<int,int>mp;
int a[200100],n;

bool chk(int x){
	mp.clear();
	for(int i=1;i<=n;++i)
		if(a[i]<=a[i-1]){
			for(auto it=mp.upper_bound(a[i]);it!=mp.end();it=mp.upper_bound(a[i]))mp.erase(it);
			++mp[a[i]];
			if(x==1)return 0;
			for(int j=a[i];mp[j]>=x;--j){
				if(j==1)return 0;
				mp[j]-=x;mp[j-1]++;
			}
		}
	return 1;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	int l=1,r=n;
	while(l<r){
		int mid=(l+r)/2;
		if(chk(mid))r=mid;
		else l=mid+1;
	}
	cout<<l<<'\n';
	return 0;
}
