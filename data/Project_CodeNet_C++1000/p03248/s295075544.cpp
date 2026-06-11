#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())

int n;
char str[100005];
bool ex[100005];
int main(){
	scanf("%s",&str);
	n = strlen(str);
	rep(i,n) ex[i+1] = str[i] == '1';
	
	bool bad = 0;
	if(ex[n]) bad = 1;
	if(!ex[1]) bad = 1;
	repn(i,n-1){
		if(ex[i] != ex[n-i]){
			bad = 1;
		}
	}
	
	if(bad){
		puts("-1");
		return 0;
	}
	
	int m = n/2;
	vector<int>vec;
	repn(i,m){
		if(ex[i]) vec.pb(i);
	}
	
	vector<P>edge;
	int nxt = 2;
	for(int i=1;i<vec.size();i++){
		int dif = vec[i]-vec[i-1];
		edge.pb(P(nxt-1,nxt+dif-1));
		rep(i,dif-1) edge.pb(P(nxt+i,nxt+dif-1));
		nxt += dif;
	}
	
	edge.pb(P(nxt-1,nxt));
	repn(i,300000){
		if(nxt+i > n) break;
		edge.pb(P(nxt,nxt+i));
	}
	for(auto a:edge){
		cout << a.fi << " " << a.sc << endl;
	}
}