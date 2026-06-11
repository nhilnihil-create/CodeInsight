#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int n;
int a[100005],b[100005],t[200005],c[100005],sum[100005],mx;
long long y;
int lowbit(int x){
	return (x&-x);
}
void insert(int x,int v){
	while(x<=2*n){
		t[x]+=v;
		x+=lowbit(x);
	}
}
int getsum(int x){
	int res=0;
	while(x>0){
		res+=t[x];
		x-=lowbit(x);
	}
	return res;
}
int check(int x){
	memset(t,0,sizeof(t));
	long long xx=0;
	for(int i=1;i<=n;i++){
		sum[i]=a[i]>=x?1:-1;
		sum[i]+=sum[i-1];
	}
	for(int i=0;i<=n;i++){
		xx+=getsum(sum[i]+n);
		insert(sum[i]+n,1);
	}
	long long ss;
	if(y%2==1) ss=(y+1)/2;
	else ss=y/2;
	if(xx>=ss) return 1;
	else return 0;
}
int main(){
	cin>>n;
	int l=1,r=1,ans;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		r=max(r,a[i]);
	}
	y=(long long)n*(n+1)/2;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<ans;
	/*for(int i=1,x;i<=n;i++){
		cin>>x;
		insrt(x,1);
		c[i]=i-getsum(x);
	}
	求每个位的逆序数 
	*/
}