#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MX=100010;

int n, A[MX], B[MX];
ll med;

int tree[4*MX], lim=300010;

void upt(int x){
	x+=100001;
	for(; x<=lim; x+=x&(-x)) tree[x]++;
}
int get(int r){
	int res=0; r+=100001;
	for(; 0<r; r-=r&(-r)) res+=tree[r];
	return res;
}


ll check(int x){
	for(int i=0; i<4*MX; i++) tree[i]=0;
	int S[MX]={};
	for(int i=1; i<=n; i++) if(A[i]<=x) S[i]++;
	for(int i=1; i<=n; i++) S[i]+=S[i-1];
	ll cnt=0;
	upt(1);
	for(int i=1; i<=n; i++){
		int x=2*S[i]-i;
		cnt+=get(x);
		upt(x+1);
	}
	return cnt;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>n; med=1LL*n*(n+1)/2; med=med/2+1;
	for(int i=1; i<=n; i++) cin>>A[i], B[i]=A[i];
	sort(B+1, B+n+1);

	int s=1, e=n;
	while(s<e){
		int m=(s+e)/2, x=B[m];
		if(check(x)>=med) e=m;
		else s=m+1;
	}
	cout<<B[s]<<'\n';
	return 0;
}