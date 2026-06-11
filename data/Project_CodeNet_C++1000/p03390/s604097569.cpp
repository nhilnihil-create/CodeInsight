#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
inline int read(){
	char ch=getchar();int x=0,f=1;
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int main(){
	//freopen("a.in","r",stdin);
	int Q=read();
	while(Q--){
		int A=read(),B=read();
		LL C=1ll*A*B;
		LL wt=sqrt(C);
		if(wt*(wt+1)<C){
			printf("%lld\n",wt*2-1);
		}
		else if(wt*wt==C){
			if(A==B)printf("%lld\n",wt*2-2);
			else printf("%lld\n",wt*2-3);
		}
		else{
			printf("%lld\n",wt*2-2);
		}
	}
}