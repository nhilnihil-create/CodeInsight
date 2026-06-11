#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <cmath>
#include <string>
#define FI first
#define SE second
#define PF push_front
#define PB push_back
#define PPF pop_front
#define PPB pop_back
#define MA make_pair
#define ll long long
#define PA pair<int,int>
#define VE vector<int>
#define VP vector<PA>
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define ROF(i,a,b) for(int i=b-1;i>=a;i--)
#define YES(i) cout<<(i?"YES":"NO")<<endl
#define Yes(i) cout<<(i?"Yes":"No")<<endl
using namespace std;
//
const int INF=1e9+7;
const int mod=1e9+7;
//
struct poi{
	int X;int Y;int Z;
	bool operator<(const poi&R)const{
		return X==R.X ? Y==R.Y ? Z<R.Z : Y<R.Y : X<R.X;
	}
};
/*
ll GCD(ll A,ll B){
  return (B==0)?(A):(GCD(B,A%B));
}
ll LCM(ll A,ll B){
  return A/GCD(A,B)*B;
}
*/
ll N,C;
ll X[100001],V[100001];
ll v[100001];
ll rv[100001];
ll n[100001];
int main(){
	cin>>N>>C;
	X[0]=0;V[0]=0;
	FOR(i,1,N+1){
		cin>>X[i]>>V[i];
	}
	v[0]=0;
	FOR(i,1,N+1){
		v[i]=v[i-1]+V[i];
	}
	FOR(i,1,N+1){
		v[i]-=X[i]*2;
	}
	int now=0;
	n[0]=0;
	FOR(i,1,N+1){
		if(v[now]<v[i]){
			now=i;
		}
		n[i]=now;
	}
	//
	reverse(X+1,X+N+1);
	reverse(V+1,V+N+1);
	rv[0]=0;
	FOR(i,1,N+1){
		rv[i]=rv[i-1]+V[i];
	}
	FOR(i,1,N+1){
		rv[i]-=C-X[i];
	}
	//
	ll ans=0;
	reverse(X+1,X+N+1);
	reverse(V+1,V+N+1);
	FOR(i,1,N+1){
		ans=max(ans,rv[i]+v[n[N-i]]);
	}
	//
	FOR(i,1,N+1){
		v[i]+=X[i];
	}
	ll ma=0;
	FOR(i,0,N+1){
		ma=max(ma,v[i]);
	}
	ans=max(ans,ma);
	//
	fill(v,v+N+1,0);
	fill(rv,rv+N+1,0);
	fill(n,n+N+1,0);
	//
	reverse(X+1,X+N+1);
	reverse(V+1,V+N+1);
	FOR(i,1,N+1){
		X[i]=C-X[i];
	}
	//
	v[0]=0;
	FOR(i,1,N+1){
		v[i]=v[i-1]+V[i];
	}
	FOR(i,1,N+1){
		v[i]-=X[i]*2;
	}
	now=0;
	n[0]=0;
	FOR(i,1,N+1){
		if(v[now]<v[i]){
			now=i;
		}
		n[i]=now;
	}
	//
	reverse(X+1,X+N+1);
	reverse(V+1,V+N+1);
	rv[0]=0;
	FOR(i,1,N+1){
		rv[i]=rv[i-1]+V[i];
	}
	FOR(i,1,N+1){
		rv[i]-=C-X[i];
	}
	reverse(X+1,X+N+1);
	reverse(V+1,V+N+1);
	FOR(i,1,N+1){
		ans=max(ans,rv[i]+v[n[N-i]]);
	}
	FOR(i,1,N+1){
		v[i]+=X[i];
	}
	ma=0;
	FOR(i,0,N+1){
		ma=max(ma,v[i]);
	}
	ans=max(ans,ma);
	cout<<ans<<endl;
	return 0;
}