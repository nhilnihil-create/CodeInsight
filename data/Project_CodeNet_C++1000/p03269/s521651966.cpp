#include<iostream>
#include<cstdio>

int n,a;
int N;

int L[70],R[70],V[70],tot;

int main(){
	scanf("%d",&n);
	while ((1<<N)<=n) N++;
	printf("%d ",N);
	for (int i=0;(1<<(i+1))<=n;i++){
		L[++tot]=i+1;R[tot]=i+2;V[tot]=0;
		L[++tot]=i+1;R[tot]=i+2;V[tot]=(1<<i);
	}
	a=(1<<(N-1));
	for (int i=N-1;i;i--){
		if ((1<<(i-1))<=n-a){
			L[++tot]=i;R[tot]=N;V[tot]=a;
			a+=(1<<(i-1));
		}
	}
	printf("%d\n",tot);
	for (int i=1;i<=tot;i++) printf("%d %d %d\n",L[i],R[i],V[i]);
}