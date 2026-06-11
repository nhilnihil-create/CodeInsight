#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;

int n;
long long x[1010],y[1010];
long long p[40];
int fx[4]={-1,1,0,0};
int fy[4]={0,0,1,-1};

int main(){
	scanf("%d",&n);
	scanf("%lld %lld",&x[1],&y[1]);
	long long flag=(x[1]+y[1]+(long long)10e9)%2;
	for(int i=2;i<=n;i++){
		scanf("%lld %lld",&x[i],&y[i]);
		if(flag!=(x[i]+y[i]+(long long)10e9)%2){
			printf("-1\n");
			return 0;
		}
	}
	for(int i=30;i>=0;i--) p[30-i+1]=(1ll<<i);
	int m=31;
	if(flag==0) p[++m]=1;
	printf("%d\n",m);
	for(int i=1;i<=m;i++) printf("%lld ",p[i]);
	printf("\n");
	long long tempx,tempy;
	long long mmin;
	int w;
	
	for(int i=1;i<=n;i++){
		long long xx=x[i],yy=y[i];
		for(int j=1;j<=m;j++){
			mmin=0x3f3f3f3f3f3f3f3f,w=0;
			for(int q=0;q<4;q++){
				tempx=xx+fx[q]*p[j];
				tempy=yy+fy[q]*p[j];
				if(abs(tempx)+abs(tempy)<mmin){
					mmin=abs(tempx)+abs(tempy);
					w=q;
				}
			}
			if(w==0) printf("R");
			else if(w==1) printf("L");
			else if(w==2) printf("D");
			else if(w==3) printf("U");
			xx+=fx[w]*p[j];
			yy+=fy[w]*p[j];
		}
		printf("\n");
	}
	
}