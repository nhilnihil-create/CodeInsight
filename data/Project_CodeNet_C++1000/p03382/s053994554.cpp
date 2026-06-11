#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int N=1e5+3,inf=0x7fffffff;
int cnt,n,a[N],maxx,fail,minn=inf;
inline int read(){
	int num=0,flag=1;
	char c=getchar();
	for(;c<'0'||c>'9';c=getchar())
	if(c=='-') flag=-1;
	for(;c>='0'&&c<='9';c=getchar())
	num=(num<<3)+(num<<1)+c-48;
	return num*flag;
}
int main(){
	n=read();
	for(int i = 1;i<=n;i++){
		a[i]=read();
		if(a[i]>maxx) maxx=a[i],fail=i;
	}
	a[fail]=0;
	int mid=maxx/2;
	int k;
	for(int i = 1;i<=n;i++){
		k=abs(a[i]-mid);
		if(k<minn){
			minn=k;
			cnt=a[i];
		}
	}
	printf("%d %d",maxx,cnt);
	return 0;
}