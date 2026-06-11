#include<cstdio>
#include<iostream>
using namespace std;
int n,r,a[200005],s[25];
long long ans;
void insert(int x){
	for(int i=1;i<=21;i++) s[i]+=x&1,x>>=1;
}
void del(int x){
	for(int i=1;i<=21;i++) s[i]-=x&1,x>>=1;
}
bool check(int x){
	for(int i=1;i<=21;i++){
		if(s[i]==1 && (x&1)==1) return 0;
		x>>=1;
	}
	return 1;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	r=1;
	insert(a[1]);
	for(int i=1;i<=n;i++){
		while(r<n && check(a[r+1])) insert(a[++r]);
		ans+=r-i+1;
		del(a[i]);
	}
	printf("%lld\n",ans);
	return 0;
}