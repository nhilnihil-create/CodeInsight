#include<iostream>
#include<cstdio>
#include<algorithm>
#define LL unsigned long long
using namespace std;
int n;
LL X,ans,A[2020200],sum[2020200];
int main(){
	scanf("%d %lld",&n,&X);
	for (int i=1;i<=n;i++) 
		scanf("%lld",&A[i]),sum[i]=A[i]+sum[i-1];
	for (int K=1;K<=n;K++){
		LL res=(LL)K*X+X*(LL)n;
		int pos=n;
		if (n<=2*K) res+=sum[n]*5;
		else{
			res+=(sum[n]-sum[n-2*K])*5;
			pos=n-2*K;int num=5;
			while (pos){
				num+=2; int x=min(pos,K);
				res+=(LL)num*(sum[pos]-sum[pos-x]);
				pos-=x;
			}
		}
		if (K==1||res<ans) ans=res;
	}
	cout<<ans;
}
