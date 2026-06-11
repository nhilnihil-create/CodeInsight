#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read(){
	ll a=0,b=getchar(),c=1;
	while(!isdigit(b))c=b=='-'?-1:1,b=getchar();
	while(isdigit(b))a=a*10+b-'0',b=getchar();
	return a*c;
}
char c[]="LDUR";
ll n,sum,x[1005],y[1005];
bool ok=true;
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		int a=read(),b=read();
		x[i]=a+b,y[i]=a-b;
	}
	for(int i=1;i<=n;i++)
		if((x[i]&1)!=(x[1]&1))
			ok=false;
	if(!ok)return puts("-1"),0;
	bool t=!(x[1]&1);
	printf("%d\n",39+t);
	if(t)printf("1 "),sum++;
	for(int i=0;i<39;i++){
		printf("%lld ",1ll<<i);
		sum+=1ll<<i;
	}
	puts("");
	for(int i=1;i<=n;i++){
		x[i]+=sum,y[i]+=sum;
		if(t)putchar(c[0]);
		for(int j=1;j<=39;j++)
			putchar(c[(((x[i]>>j)&1)<<1)|((y[i]>>j)&1)]);
		puts("");
	}
	return 0;
}