#include<bits/stdc++.h>
using namespace std;
const int Max_N=1e5;
int N,A[Max_N+10]={},B[Max_N+10]={},C[Max_N+10]={},P[Max_N*3+10]={};
inline int lowbit(int x){
	return x & -x ;
}
inline void Add(int x,int k){
	for(;x<=Max_N*3;x+=lowbit(x)) P[x]+=k;
}
inline long long Ask(int x){
	long long Sum=0;
	for(;x>0;x-=lowbit(x)) Sum+=P[x];
	return Sum;
}
inline bool chck(int x){
	long long Cnt=1;
	for(int i=1;i<=N;i++)
	 if(A[i]<=x) B[i]=0;
	 else B[i]=1;
	for(int i=1;i<=N;i++) B[i]+=B[i-1];
	for(int i=1;i<=N;i++) Add(B[i]*2-i+N+1,1);
	for(int i=1;i<=N;i++){
		Cnt+=(N-i+1)-Ask(B[i-1]*2-(i-1)-1+N+1);
		Add(B[i]*2-i+N+1,-1);
	}
	return Cnt*2<N*1LL*(N+1)/2;
}
int main(){
	scanf("%d",&N);
	for(int i=1;i<=N;i++) scanf("%d",&A[i]),C[i]=A[i];
	sort(C+1,C+N+1);
	int l=1,r=N;
	for(;l+1<r;){
		int Mid=(l+r)>>1;
		if(chck(C[Mid])) r=Mid;
		else l=Mid;
	}
	if(chck(C[l])) printf("%d\n",C[l]);
	else printf("%d\n",C[r]);
	return 0; 
} 