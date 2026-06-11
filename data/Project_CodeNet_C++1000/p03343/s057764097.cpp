#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstdio>
#include <cmath>
using namespace std;
const int maxn=2000+5;
int a[maxn],num[maxn],len;
int n,k,m;
bool b[maxn];
int c[maxn];
inline bool chk2(int si,int x){
	int r=a[si]+x,l=a[si];
	int ans=0;
	for (int i=1;i<=n;i++){
		if (l<=a[i]&&a[i]<=r){
			c[i]=1;
		}
		else if (a[i]>r) c[i]=2;
		else c[i]=0;
	}
	int cur1=0,cur2=0;
	for (int i=1;i<=n;i++){
		if (si==i) continue;
		if (c[i]==0){
			if (cur1>=k){
				ans+=min(cur2,cur1-k+1);
			}
			cur2=cur1=0;
			continue;
		}
		if (c[i]==2){
			cur1++;
			continue;
		}
		if (c[i]==1){
			cur1++;
			cur2++;
			continue;
		}
	}
	if (cur1>=k){
		ans+=min(cur2,cur1-k+1);
	}
	return ans>=m-1;
}
inline bool chk(int x){
	for (int i=1;i<=n;i++){
		if (b[i]==0) continue;
		if (chk2(i,x)){
			return true;
		}
	}
	return false;
}
int main(){
	cin>>n>>k>>m;
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for (int l=1;l+k-1<=n;l++){
		int r=l+k-1;
		int cur=2e9;
		for (int i=l;i<=r;i++){
			cur=min(cur,a[i]);
		}
		for (int i=l;i<=r;i++){
			if (cur==a[i]) b[i]=1;
		}
	}
	int l=0,r=1e9,ans=-1;
	while(l<=r){
		int mid=(l+r)/2;
		if (chk(mid)){
			r=mid-1;
			ans=mid;
		}
		else l=mid+1;
	}
	cout<<ans<<endl;
}