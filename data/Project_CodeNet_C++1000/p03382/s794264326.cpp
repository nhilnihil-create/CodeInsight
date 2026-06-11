#include<bits/stdc++.h>

using namespace std;

inline int read(){
	char ch=getchar();int x=0,f=1;
    while(ch<'0' || ch>'9') {
       if(ch=='-') f=-1;
	  	  ch=getchar();
	}
    while(ch<='9' && ch>='0') {
	   x=x*10+ch-'0';
	   ch=getchar();
	}
    return x*f;
}

int a[100000];

int main(){
	int n=read(),ma=0,mi=0;
	for(int i=1;i<=n;i++){
		a[i]=read();
		ma=max(ma,a[i]);
	}
	for(int i=1;i<=n;i++){
		if(abs(a[i]*2-ma)<abs(mi*2-ma)){
			mi=a[i];
		}
	}
	printf("%d %d\n",ma,mi);
	return 0;
}
