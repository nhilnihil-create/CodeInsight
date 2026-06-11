#include<bits/stdc++.h>
using namespace std;
int L,e,n,l;
struct as{
	int a,b,c;
}a[105];
int xx(int x){
	return -x&x;
}
int main(){
	scanf("%d",&L);
	for(int i=20;i>=0;i--){
		if(L&(1<<i)){
			n=i+1;
			break;
		}
	}	
	for(int i=1;i<n;i++){
		a[++e].a=i,a[e].b=i+1,a[e].c=1<<(n-i-1);
		a[++e].a=i,a[e].b=i+1,a[e].c=0;
	}
	if(L-xx(L)){
		for(int i=20;i>=0;i--){
			if((L-1)&(1<<i)){
				if(l)a[++e].a=1,a[e].b=n-i,a[e].c=l;
				l|=(1<<i);
			}
		}
		if(l)a[++e].a=1,a[e].b=n,a[e].c=l;
	}
	printf("%d %d\n",n,e);
	for(int i=1;i<=e;i++){
		printf("%d %d %d\n",a[i].a,a[i].b,a[i].c);
	}
	return 0;
}