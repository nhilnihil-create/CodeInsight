#include<iostream>
#include<cstring>
#include<cstdio>
#include<unordered_map>
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
const int MAXN = 200010;
const int INF = 2147483600;

unordered_map<int,int> mp;
int a[MAXN+1];
int N; int ans;

int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	N=read(); for(int i=1;i<=N;i++) {
		int x=read(); mp[x]++; a[i]=x;
	} sort(a+1,a+N+1);
	for(int i=N;i>=1;i--){
		if(a[i]==a[i+1]) continue;
		bool flag=0; int now=mp[a[i]];
		for(int j=30;j>=0;j--) if((1LL<<j)==a[i]) flag=1;
		if(flag) {ans+=now/2; now&=1;}
		for(int j=30;j>=0&&now;j--){
			int to=(1<<j); if(to-a[i]>=a[i]) continue;
			if(to<=a[i]) break;
			int d=to-a[i],p=min(now,mp[d]);
			if(p){ mp[d]-=p; now-=p; ans+=p; }
		}
	} printf("%d\n",ans);
	return 0;
}