#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
const int N=1010;
int a[N],b[N];
inline int gi() {
    int x=0,o=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') ch=='-'?o=-1:0,ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return o*x;
}
inline void work(int x,int y) {
    for(int i=30;~i;i--) {
	if(abs(x)>abs(y)) {
	    if(x<0) x+=1<<i,putchar('L');
	    else x-=1<<i,putchar('R');
	}
	else {
	    if(y<0) y+=1<<i,putchar('D');
	    else y-=1<<i,putchar('U');
	}
    }
}
int main() {
    int n,t;
    cin>>n;
    for(int i=1;i<=n;i++) {
	int x=a[i]=gi(),y=b[i]=gi();
	if(i==1) t=(x+y)&1;
	else if(((x+y)&1)!=t) return cout<<-1,0;
    }
    t^=1,cout<<31+t<<endl;
    if(t) cout<<1<<' ';
    for(int i=30;~i;i--) printf("%d ",1<<i);
    for(int i=1;i<=n;i++) {
	puts("");
	if(t) putchar('R');
	work(a[i]-t,b[i]);
    }
    return 0;
}