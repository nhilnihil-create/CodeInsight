#include<bits/stdc++.h>
#define rep(X,A,B) for(int X=A;X<=B;++X)
#define tep(X,A,B) for(int X=A;X>=B;--X)
#define LL long long
const int N=200010;
using namespace std;

LL M;
int n,maxn;
int a[N],b[N];
LL num[N<<1];

void READ(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]),b[i]=a[i];
	M=1LL*(n+1)*n/2;
	maxn=n<<1;
	maxn++;
}

int lowbit(int x){
	return x&(-x);
}

void ADD(int x,LL val){
	while(x<=maxn){
		num[x]+=val;
		x+=lowbit(x);
	}
}

LL QUE(int x){
	if(x<0)return 0;
	LL res=num[0];
	while(x>0){
		res+=num[x];
		x-=lowbit(x);
	}
	return res;
}

LL GET(int x){
	rep(i,0,maxn)num[i]=0;
	ADD(n+1,1);
	int now=0;
	LL res=0;
	rep(i,1,n){
		if(a[i]<=x)now++;else now--;
		res+=1LL*QUE(now+n);
		ADD(now+n+1,1);
	}
	return res;
}

void SOLVE(){
	sort(b+1,b+n+1);
	int l=1,r=n,res=1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(GET(b[mid])<=M/2)l=mid+1;
		else r=mid-1,res=mid;
	}
	printf("%d\n",b[res]);
}

int main(){
	READ();
	SOLVE();
	return 0;
}