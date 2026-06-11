#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <iostream>
#include <algorithm>
#define MAX 100007
#define MAXN 1007
#define MAXM 1007
#define INF  0x3f3f3f3f
#define NINF 0xc0c0c0c0
#define MOD 1000000007
const double EXP=1e-10;
using namespace std;
typedef long long ll;
typedef vector<ll> Vec;
typedef vector<Vec> Mat;
//================================================================================================
ll n,c;
ll x[MAX];
ll mx[MAX]; 
ll v[MAX];
ll ans,t,maxs;
int main(){
	scanf("%lld%lld",&n,&c);
	for(ll i=1;i<=n;i++) {
		scanf("%lld%lld",x+i,v+i);
	}
	t=0;
	for(int i=1;i<=n;i++) {
		t+=v[i];
		if(t-x[i]>mx[i-1]) 
			mx[i]=t-x[i];
		else
			mx[i]=mx[i-1];
	}
	ans=max(ans,mx[n]);
	t=0;
	for(int i=n;i>=1;i--) {
		t+=v[i];
		ans=max(ans,t-2*(c-x[i])+mx[i-1]);
	}
	t=0;
	for(int i=n;i>=1;i--) {
		t+=v[i];
		if(t-c+x[i]>mx[i+1]) 
			mx[i]=t-c+x[i];
		else
			mx[i]=mx[i+1];
	}
	t=0;
	ans=max(ans,mx[1]);
	for(int i=1;i<=n;i++) {
		t+=v[i];
		ans=max(ans,t-2*x[i]+mx[i+1]);
	}
	printf("%lld\n",ans);
	return 0;
}