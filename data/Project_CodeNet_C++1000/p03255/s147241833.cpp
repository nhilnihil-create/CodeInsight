#include <bits/stdc++.h>
#define ll long long
#define FOR(i,a,b) for(int i=a;i<b;i++)
using namespace std;

int f(int k){
	if(k==0) return 5;
	else if(k==1) return 0;
	else return 2;
}

ll x[200001], x2[200001];

int main(){
	int n,X; cin>>n>>X;
	FOR(i,0,n) cin>>x[i];
	x2[0]=x[0];
	FOR(i,1,n) x2[i]=x2[i-1]+x[i];

	ll m=1e18;
	FOR(k,1,n+1){
		int t=0;
		ll ans=0;
		while(n-1-t*k>=0){
			ans+=f(t)*x2[n-1-t*k];
			if(ans>m) break;
			t++;
		}
		if(ans>m) continue;
		ans+=(ll)X*(n+k);
		m=min(ans,m);
	}
	cout<<m<<endl;
}