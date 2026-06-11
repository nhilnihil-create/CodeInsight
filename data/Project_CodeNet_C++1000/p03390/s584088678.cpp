#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
void File(){
	freopen("1.in","r",stdin);
	freopen("2.out","w",stdout);
}
#define REP(i,a,b) for(register int i=a;i<=b;++i)
#define DREP(i,a,b) for(register int i=a;i>=b;--i)
#define MREP(i,x) for(register int i=beg[x];i;i=E[i].last)
#define ll long long
int n;
int main(){
//	File();
	scanf("%d",&n);
	REP(i,1,n){
		ll a,b;
		scanf("%lld%lld",&a,&b);
		ll dd=sqrt(a*b),ans=dd*2-1;
		if(dd*dd==a*b){
			if(a==b)ans--;
			else ans-=2;
		}
		else if(dd*(dd+1)>=a*b)ans--;
		cout<<ans<<endl;
	}	
	return 0;
}