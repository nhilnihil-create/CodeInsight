#include<bits/stdc++.h>
using namespace std;

const int N=1e5+100;

int op[N*3],cl[N*3];
int n;

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int l,r;
		scanf("%d%d",&l,&r);
		op[l+N]+=1;
		cl[r+N]+=1;
	}
	long long ans=0;
	int cl_l=0,op_r=n;
	for(int i=0;i<3*N-1;i++){
		cl_l+=cl[i];
		op_r-=op[i];
		if(i-N<0) ans+=min(cl_l,op_r+1);
		else ans+=min(cl_l+1,op_r);
	}
	printf("%lld",ans*2);
	return 0;
}