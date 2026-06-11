#include<iostream>
#include<cstdio>
#define Abs(x) ((x)<0?-(x):(x))
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
typedef long long ll;
const int N=1001000;
int n,m=30,tmp;
ll X[N],Y[N];
void work(ll x,ll y){
	if(tmp) cout<<'R';
	ROF(i,m,0){
		ll dx=Abs(x),dy=Abs(y);
		if(dx<dy && y>0) cout<<'U',y-=1ll<<i;
		else if(dx<dy && y<0) cout<<'D',y+=1ll<<i;
		if(dx>dy && x>0) cout<<'R',x-=1ll<<i;
		else if(dx>dy && x<0) cout<<'L',x+=1ll<<i;
	}puts("");
}
int main(){
	scanf("%d",&n);
	FOR(i,1,n) scanf("%lld%lld",&X[i],&Y[i]);
	FOR(i,2,n)if((Abs(X[i]+Y[i])^Abs(X[1]+Y[1]))&1) return puts("-1"),0;
	if(Abs(X[1]+Y[1])%2==0){tmp=1;FOR(i,1,n) X[i]--;}
	cout<<m+tmp+1<<'\n';
	if(tmp) cout<<1<<' ';ROF(i,m,0) cout<<(1ll<<i)<<' ';cout<<'\n';
	FOR(i,1,n) work(X[i],Y[i]);
	return 0;
}