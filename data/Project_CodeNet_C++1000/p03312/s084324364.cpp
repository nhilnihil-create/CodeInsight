#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
#define F first
#define S second
#define pb push_back
#define INF 1e18
#define MOD 1000000007
#define N 1000005
#define BB(V) V[V.size()-2]
#define ex(V) return printf(V),0
using namespace std;
ll sum[200005];
ll calc(int gs,int ge,int x){
	return abs(sum[x-1]-sum[gs-1]-sum[ge]+sum[x-1]);
}
pii TS(int s,int e,int gs,int ge){
	if(s==e)return {sum[s-1]-sum[gs-1],sum[ge]-sum[s-1]};
	if(s+1==e){
		if(calc(gs,ge,s)<calc(gs,ge,e))return {sum[s-1]-sum[gs-1],sum[ge]-sum[s-1]};
		return {sum[e-1]-sum[gs-1],sum[ge]-sum[e-1]};
	}
	int m1=(2*s+e)/3,m2=(s+2*e)/3;
	if(calc(gs,ge,m1)<calc(gs,ge,m2))return TS(s,m2-1,gs,ge);
	return TS(m1+1,e,gs,ge);
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int t;
		scanf("%d",&t);
		sum[i]=sum[i-1]+t;
	}
	ll mn=INF;
	for(int i=2;i<n-1;i++){
		pii t1=TS(2,i,1,i),t2=TS(i+2,n,i+1,n);
		mn=min(mn,max(max(t1.F,t1.S),max(t2.F,t2.S))-min(min(t1.F,t1.S),min(t2.F,t2.S)));
	}
	printf("%lld",mn);
}