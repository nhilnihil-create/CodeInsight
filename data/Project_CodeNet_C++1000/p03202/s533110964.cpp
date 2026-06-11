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
const int N=200010;
int n,a[N],p[N],z[N],tp;
bool ck(int k){
	tp=0;p[0]=0;z[0]=-N;
	F(i,2,n)
		if(a[i]<=a[i-1]){
			if(k==1)return 0; 
			while(p[tp]>a[i])--tp;
			if(p[tp]!=a[i]){
				++tp;
				p[tp]=a[i];
				z[tp]=1;
			}
			else{
				++z[tp];
			}
			while(z[tp]==k){
					if(p[tp-1]==p[tp]-1){
						--tp;
						++z[tp];
					}
					else{
						--p[tp];
						z[tp]=1;
					}
				}
		}
	return z[0]==-N;
}
int main(){
	//freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	n=R();
	F(i,1,n)a[i]=R();
	int ll=1,rr=n+1,mid,ans;
	while(ll<=rr){
		mid=(ll+rr)/2;
		if(ck(mid))ans=mid,rr=mid-1;
		else ll=mid+1;
	}
	cout<<ans;
    return 0;
}
