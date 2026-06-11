#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

#define LL long long
#define fgx cerr<<"--------------"<<endl;
#define dgx cerr<<"=============="<<endl;

inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	return x*f;
}
const int MAXN = 100010;
const int INF = 2147483600;

int N; LL ans,lst,mn;

int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	N=read(); mn=1;
	for(int i=1;i<=N;i++){
		LL x=read();
		if(i-x<mn) { puts("-1"); return 0; }
		if(i-x==mn) {lst=x; continue;}
		mn=i-x; ans+=lst; lst=x; 
	} printf("%lld\n",ans+lst);
	return 0;
}


