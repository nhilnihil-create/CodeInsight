#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;

#define fr first
#define sc second
#define chmax(a,b) a=max(a,b)
#define chmin(a,b) a=min(a,b)

int main(){
	static ll n,c;
	static ll x[2][100010],v[100010];
	scanf("%lld%lld",&n,&c);
	for(int i=0;i<n;i++){
		scanf("%lld%lld",&x[0][i],&v[i]);
		x[1][i]=c-x[0][i];
	}
	reverse(x[1],x[1]+n);
	
	static ll sum[2][100010]={};
	for(int i=0;i<n;i++){
		if(i==0){
			sum[0][i]=v[i]-x[0][i];
			sum[1][i]=v[n-1]-x[1][i];
		}
		else {
			sum[0][i]=sum[0][i-1]+v[i]-(x[0][i]-x[0][i-1]);
			sum[1][i]=sum[1][i-1]+v[n-1-i]-(x[1][i]-x[1][i-1]);
		}
	}
	static ll MAX[2][100010];
	for(int i=0;i<n;i++){
		MAX[0][i]=sum[0][i];
		MAX[1][i]=sum[1][i];
	}
	for(int i=1;i<=n-1;i++){
		chmax(MAX[0][i],MAX[0][i-1]);
		chmax(MAX[1][i],MAX[1][i-1]);
	}
	ll ret=max(MAX[0][n-1],MAX[1][n-1]);
	for(int i=0;i<n-1;i++){
		chmax(ret,sum[0][i]-x[0][i]+MAX[1][n-2-i]);
		chmax(ret,sum[1][i]-x[1][i]+MAX[0][n-2-i]);
	}
	chmax(ret,0LL);
	cout<<ret<<endl;
}

