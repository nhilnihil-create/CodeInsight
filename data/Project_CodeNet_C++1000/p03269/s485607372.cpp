#include<bits/stdc++.h>
using namespace std;
int L;
int l[65],r[65],w[65],N,M;
void ins(int ll,int rr,int ww){
	l[++M]=ll;r[M]=rr;w[M]=ww;
}
int main(){
	register int i;
	scanf("%d",&L);N=1;
	while(L){
		if(L&1) ins(N,-1,L-1),L--;
		else ins(N,N+1,L>>1),ins(N,N+1,0),N++,L>>=1;
	}
	printf("%d %d\n",N,M-1);
	for(i=1;i<M;i++) printf("%d %d %d\n",l[i],r[i]==-1?N:r[i],w[i]);
}