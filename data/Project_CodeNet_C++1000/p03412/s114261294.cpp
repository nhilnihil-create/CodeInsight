#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=200050;
int n;
int a[maxn],b[maxn],s[maxn];
inline int erfen(int x){
	int l=1,r=n+1;
	while(l<r){
		int m=(l+r)>>1;
		if(s[m]>=x)r=m;
		else l=m+1;
	}
	return l;
}
int main(){
	scanf("%d",&n);
	for(register int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(register int i=1;i<=n;i++){
		scanf("%d",&b[i]);
	}
	int ans=0;
	for(register int i=1;i<=29;i++){
		int tmp=(1<<i)-1;
		for(register int j=1;j<=n;j++)s[j]=b[j]&tmp;
		sort(s+1,s+n+1);
		int cnt=0;
		for(register int j=1;j<=n;j++){
			cnt+=n-erfen((1<<(i-1))-(a[j]&tmp))+1;
		}
		for(register int j=1;j<=n;j++){
			cnt-=erfen((1<<i)+(1<<(i-1))-(a[j]&tmp))-erfen((1<<i)-(a[j]&tmp));
		}
		if(cnt&1){
			ans+=(1<<(i-1));
		}
	}
	cout<<ans<<endl;
}