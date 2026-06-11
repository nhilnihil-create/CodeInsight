#include <bits/stdc++.h>
typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,a) FOR(i,0,a)
	
using namespace std;
const int MAX_N=1e5,MAX_M=1e5;
int N,M;
int ufpar[MAX_N];
int uffndpar(int v){
	if(v==ufpar[v]){
		return v;
	}
	return ufpar[v]=uffndpar(ufpar[v]);
}
bool same(int s,int t){
	s=uffndpar(s);
	t=uffndpar(t);
	return s==t;
}
void unite(int s,int t){
	s=uffndpar(s);
	t=uffndpar(t);
	ufpar[s]=t;
}
vector<int> G[MAX_N];
int A[MAX_M],B[MAX_M];
bool used[MAX_M];
int dst[MAX_N];
void caldst(int v,int p,int d){
	dst[v]=d;
	for(auto e:G[v]){
		if(e!=p){
			caldst(e,v,d+1);
		}
	}
}
int main(){
	cin>>N>>M;
	REP(i,N)ufpar[i]=i;
	REP(i,M){
		int a,b;
		cin>>a>>b;
		a--;
		b--;
		A[i]=a;
		B[i]=b;
		if(!same(a,b)){
			unite(a,b);
			G[a].push_back(b);
			G[b].push_back(a);
			used[i]=true;
		}
	}
	caldst(0,-1,0);
	bool flg=false;
	REP(i,M){
		if(used[i])continue;
		if(abs(dst[A[i]]-dst[B[i]])%2==0){
			flg=true;
		}
	}
	ll ans=-M;
	if(flg){
		ans+=(ll)N*(N-1)/2;
	}else{
		ll cnt=0;
		REP(v,N){
			if(dst[v]%2==1){
				cnt++;
			}
		}
		ans+=cnt*(N-cnt);
	}
	cout<<ans<<endl;
}