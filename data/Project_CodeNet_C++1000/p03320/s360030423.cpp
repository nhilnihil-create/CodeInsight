#include<cstdio>
#define ll long long
ll x;int n;
int f(ll x){
	int q=0;
	while (x) q+=x%10,x/=10;
	return q;
}
int main(){
	scanf("%d",&n);x=1;ll la=1;
	printf("1\n");
	for (int i=2;i<=n;i++){
		if (la+x>x*f(la+x)) x*=10;
		printf("%lld\n",la+=x);
	}
	return 0;
}