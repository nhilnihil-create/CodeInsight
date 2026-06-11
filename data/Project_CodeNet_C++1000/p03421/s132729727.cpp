#include<bits/stdc++.h>
#define ll long long
using namespace std;
int la,hh,n,A,B,i,j,a[500001];
int main(){
	scanf("%d%d%d",&n,&A,&B);
	if(B+A>n+1)return puts("-1"),0;
	if((ll)B*A<(ll)n)return puts("-1"),0;
	for(i=B;i;i--)printf("%d ",i);
	la=B;
	for(i=2;i<A;i++){
		hh=min(B,n-la-(A-i));
		for(j=hh+la;j>la;j--)printf("%d ",j);
		la+=hh;
	}
	for(i=n;i>la;i--)printf("%d ",i);
}