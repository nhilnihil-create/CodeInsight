#include<cstdio>
#include<iostream>
int n,m=1,a[10000000],x[50];
long long ans;
void ins(int nc){
	for(int i=1;i<=21;i++){
		x[i]+=nc&1;
		nc=nc/2;
	}
}
void del(int nc){
	for(int i=1;i<=21;i++){
		x[i]-=nc&1;
		nc=nc/2;
	}
}
bool check(int nc){
	for(int i=1;i<=21;i++){
		if(x[i]==1&&(nc&1)==1) return false;
		nc=nc/2;
	}
	return true;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	ins(a[1]);
	for(int i=1;i<=n;i++){
		while(m<n&&check(a[m+1])) ins(a[++m]);
		ans+=m-i+1;
		del(a[i]);
	}
	printf("%lld\n",ans);
	return 0;
}