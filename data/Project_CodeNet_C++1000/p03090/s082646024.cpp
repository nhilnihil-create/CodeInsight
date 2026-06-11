//ios::sync_with_stdio(false);
#include<bits/stdc++.h>
#define LL long long
#define F(x,y,z) for(int x=y;x<=z;++x)
#define D(x,y,z) for(int x=y;x>=z;--x)
#define ckmax(a,b) (a)=max(a,b)
#define ckmin(a,b) (a)=min(a,b)
#define pb push_back
using namespace std;
LL R(){
    LL ans=0,f=1;char c=getchar();
    for(;c<'0'||c>'9';c=getchar()) if (c=='-') f=-1;
    for(;c>='0'&&c<='9';c=getchar()) ans=ans*10+c-'0';
    return ans*f;
}
const int N=10010;
int n,cnt;
vector<int> v[N];
int main(){
	//freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	n=R();
	if(n&1){
		v[1].pb(n);
		--n;
		++cnt;
	}
	F(i,1,n/2){
		++cnt;
		v[cnt].pb(i);
		v[cnt].pb(n-i+1);
	}
	int s=0;
	F(i,1,cnt)
		F(j,i+1,cnt)s+=v[i].size()*v[j].size();
	printf("%d\n",s);
	F(i,1,cnt)
		F(j,i+1,cnt)
			for(auto x:v[i])
				for(auto y:v[j])
					printf("%d %d\n",x,y);
    return 0;
}