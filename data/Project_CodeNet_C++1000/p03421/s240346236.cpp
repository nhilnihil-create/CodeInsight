#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(),x.end()
#define lop(i,s,t) for(int i=s;i<(t);++i)
#define rep(i,s,t) for(int i=s;i<=(t);++i)
#define dec(i,s,t) for(int i=s;i>=(t);--i)
using namespace std; 

int n,a,b,cur;

int main(int argc,char *argv[]){
#ifdef CURIOUSCAT
	//freopen("dat.in","r",stdin); 
#endif
	cin>>n>>a>>b; 
	if(a==1){
		if(b!=n)return puts("-1"),0; 
		dec(i,n,1)printf("%d ",i);puts(""); 
		return 0; 
	}
	int x=(n-b)/(a-1),y=(n-b)%(a-1);
	if(x==0||x>b||(y&&x+1>b))return puts("-1"),0;

	dec(i,b,1)printf("%d ",i); cur=b;
	rep(z,1,y){ dec(i,x+1,1)printf("%d ",cur+i); cur+=x+1; }
	rep(z,1,a-1-y){ dec(i,x,1)printf("%d ",cur+i); cur+=x; }
	puts(""); 
	return 0; 
}
