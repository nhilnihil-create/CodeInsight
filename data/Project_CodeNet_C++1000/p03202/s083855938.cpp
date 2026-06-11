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
const int MAXN = 200010;
const int INF = 2147483600;

#define op first
#define ed second 
int N; int a[MAXN+1];
pair<int,int> s[MAXN+1]; int top;

inline bool check(int k){
	top=0; for(int i=1;i<=N;i++){
		int len=a[i];
		if(s[top].ed<len){
			s[++top]=make_pair(1,len);
			continue;
		}
		while(top>1&&s[top-1].ed>=len) --top;
		s[top].ed=min(s[top].ed,len);
		while(top&&s[top].op==k) --top;
		if(!top) return 0;
		int ps=s[top].ed,val=s[top].op;
		if(ps-1==s[top-1].ed) --top;
		if(ps>1) s[top].ed=ps-1;
		s[++top]=make_pair(val+1,ps); 
		if(len>ps) s[++top]=make_pair(1,len);
	} return 1;
}
int ans;

int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	N=read(); for(int i=1;i<=N;i++) a[i]=read();
	int l=1,r=N; while(l<=r){
		int mid=(l+r)>>1; if(check(mid)) ans=mid,r=mid-1;
		else l=mid+1;
	} printf("%d\n",ans);
	return 0;
}


