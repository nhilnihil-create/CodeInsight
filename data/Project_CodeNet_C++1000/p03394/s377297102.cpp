#include<iostream>
#include<cstdio>
bool a[30000+11]={};
int gcd(int a,int b){
	while(a^=b^=a^=b%=a);
	return b;
}
int main(){
	int n;
	scanf("%d",&n);
	int s=0;
	int pos=1;
	for(int i=1;i<n;++i){
		while(pos%2!=0&&pos%3!=0)++pos;
		a[pos]=1;
		printf("%d ",pos);
		s+=pos;
		++pos;
	}
	for(int i=1;i<=30000;++i){
		if(!a[i]&&gcd(s,i)>1&&(s+i)%6==0){
			printf("%d",i);
			return 0;
		}
	}
}