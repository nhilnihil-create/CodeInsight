#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int tr[200010];
int lb(int pos){return pos & (-pos);}
void mdf(int pos,int wh){
	while(pos<=200000){
		tr[pos]+=wh;
		pos+=lb(pos);
	}
}
long long fnd(int pos){
	long long ret=0;
	while(pos){
		ret+=tr[pos];
		pos-=lb(pos);
	}
	return ret;
}
int N,A[100010];
int L,R,M;
int qzh[100010];
bool check(int md){
	for(int i=1;i<=N;i++)
		qzh[i]=qzh[i-1]+((A[i]<=md)?-1:1);
	long long tj=0;
	for(int i=0;i<=N;i++){
		tj+=fnd(qzh[i]);
		mdf(qzh[i],1);
	}
	for(int i=N;i+1;i--)	mdf(qzh[i],-1);
	if(tj*2>=(1ll*(N+1)*N)/2)	return true;
	return false;
}
int main(){
	scanf("%d",&N);
	qzh[0]=N+1;
	for(int i=1;i<=N;i++)	scanf("%d",&A[i]);
	L=0;R=1e9+10;
	while(L+1<R){
		M=(L+R)>>1;
		if(check(M))	L=M;
		else	R=M;
	}
	printf("%d\n",(!check(L))?L:R);
	return 0;
}