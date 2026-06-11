#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=200007;

int n,flag,l,r,mid,ans,a[N];
int tp,stk[N],num[N];

int check(){
	tp=num[0]=0;
	for(int i=1;i<=n;++i){
		if(a[i]>a[i-1])continue;
		if(!tp)stk[++tp]=a[i],num[tp]=1;
		else{
			while(tp>0&&stk[tp]>a[i])--tp;
			if(tp>0&&stk[tp]==a[i]){
				++num[tp];
				while(tp>0&&num[tp]==mid){
					int nxt=stk[tp]-1;
					--tp;
					if(stk[tp]==nxt)++num[tp];
					else stk[++tp]=nxt,num[tp]=1;
				}
			}else stk[++tp]=a[i],num[tp]=1;
		}
		if(num[0]>0)return 0;
	}
	return 1;
}

int main(){
	//freopen("c.in","r",stdin);
	scanf("%d",&n),flag=1;
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),flag&=a[i]>a[i-1];
	if(flag)printf("1\n");
	else{
		l=2,r=1000000;
		while(l<=r){
			mid=l+r>>1;
			if(check())r=mid-1,ans=mid;
			else l=mid+1;
		}
		printf("%d\n",ans);
	}
	return 0;
}
