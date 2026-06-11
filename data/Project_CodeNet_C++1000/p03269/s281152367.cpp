#include<cstdio>
int L,n,cnt,u[110],v[110],w[110],_2[110];
int main(){
	scanf("%d",&L);
	L--;
	_2[0]=1;
	for(int i=1;;i++){
		_2[i]=_2[i-1]*2;
		if(_2[i]>L+1){
			n=i;
			break;
		}
	}
	printf("%d ",n);
	int now=1;
	for(int i=1;i<n;i++,now*=2){
		u[++cnt]=i,v[cnt]=i+1,w[cnt]=now;
		u[++cnt]=i,v[cnt]=i+1,w[cnt]=0;
	}
	for(int i=n;i>=1;i--){
		if(L-now+1<_2[i-1]||L-now+1>=_2[i])continue;
		u[++cnt]=i,v[cnt]=n,w[cnt]=now;
		now=now+_2[i-1];
	}
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;i++)
		printf("%d %d %d\n",u[i],v[i],w[i]);
}