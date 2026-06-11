#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,i,la,m,a[100010],sum,j,b[5];
int main(){
	scanf("%d",&n);
	if(n==3){
		puts("2 5 63");return 0;
	}
	if(n<=20){
		a[1]=2;a[2]=4;a[3]=3;a[4]=9;la=12;
		for(i=5;i<=n;i++){
			a[i]=la;la+=6;
		}
		for(i=1;i<=n;i++)printf("%d ",a[i]);
		return 0;
	}
	b[1]=2;b[2]=4;b[3]=3;b[4]=6;
	for(i=1;i<=5000;i++){
		a[++m]=b[1];a[++m]=b[2];a[++m]=b[3];a[++m]=b[4];
		for(j=1;j<=4;j++)b[j]+=6;
	}
	for(i=1;i<=n;i++){sum=(sum+a[i])%6;
	}
	if(sum!=0){
		if(n%4==0){
			a[n-1]+=9;
		}
		if(n%4==1){
			if(n%8==1)a[n]+=4;
			 else{
			 	a[n-1]+=4;a[n-2]+=9;
			 }
		}
		if(n%4==2){
			a[n-3]+=9;
		}
		if(n%4==3){
			a[n]+=3;
		}
	}
	for(i=1;i<=n;i++)printf("%d ",a[i]);
}