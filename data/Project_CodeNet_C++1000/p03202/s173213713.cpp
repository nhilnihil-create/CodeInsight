#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,a[201000];
bool check(int k){
	map<int,int> mp;
	for(int i=2;i<=n;i++)
		if(a[i]<=a[i-1]){
			while(mp.size()&&(--mp.end())->first>a[i]) mp.erase(--mp.end());
			mp[a[i]]++;
			int now=a[i];
			while(now>0&&mp[now]>=k) mp.erase(now),mp[--now]++;
			if(!now) return 0;
		}
	return 1;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	int flag=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>1&&a[i]<=a[i-1]) flag=1;
	}
	if(!flag){puts("1");return 0;}
	int l=1,r=n;
	while(l+1<r){
		int mid=l+r>>1;
		cerr<<mid<<'\n';
		if(check(mid)) r=mid;
		else l=mid;
	}
	cout<<r<<'\n';
	return 0;
}
