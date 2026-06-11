#include<cstdio>
#define ll long long
using namespace std;
const int N=1e5+5;
int n,l=0,r=1000000001,A[N],C[N],T[N];
ll Merge(int l,int r){
	if(l==r)return 0;
	int mid=(l+r)/2;
	int i=l,j=mid+1,k=l;
	ll ret=Merge(l,mid)+Merge(mid+1,r);
	while(i<=mid&&j<=r){
		if(C[i]<=C[j])T[k++]=C[i++];
		else ret+=i-l,T[k++]=C[j++];
	}
	while(i<=mid)T[k++]=C[i++];
	while(j<=r)ret+=i-l,T[k++]=C[j++];
	for(int x=l;x<=r;++x)C[x]=T[x];
	return ret;
}
bool Check(int x){
	for(int i=1;i<=n;++i)C[i]=(A[i]>=x?1:-1)+C[i-1];
	return Merge(0,n)*2>=1ll*n*(n+1)/2;
}
int main(){
	scanf("%d",&n);
//	for(int i=1;i<=n;++i)scanf("%d",&C[i]);
//	printf("%d\n",Merge(1,n));
	for(int i=1;i<=n;++i)scanf("%d",&A[i]);
	while(l+1<r){
		int mid=(l+r)/2;
		if(Check(mid))l=mid;
		else r=mid;
	}
	printf("%d\n",l);
}