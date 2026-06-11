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

int H,W,N;
vector<int> vec[MAXN+1];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	H=read(),W=read(),N=read();
	for(int i=1;i<=N;i++){
		int x=read(),y=read();
		vec[y].push_back(x);
	}
	for(int i=1;i<=W;i++) sort(vec[i].begin(),vec[i].end());
	int now=0,ans=H;
	for(int i=1;i<=W;i++){
		++now; int sz=vec[i].size(),dv=0; 
		while(dv<sz&&vec[i][dv]<now) ++dv; int pre=now-1;
		while(dv<sz&&vec[i][dv]==pre+1) pre=vec[i][dv],++dv,++now;
		for(;dv<sz;dv++){
			if(dv&&vec[i][dv]==vec[i][dv-1]+1) continue;
			ans=min(ans,vec[i][dv]-1); break;
		}
	}
	cout<<ans<<endl;
	return 0;
}


