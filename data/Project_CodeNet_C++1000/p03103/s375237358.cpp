#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#include <stdio.h>
#include <math.h>
#include <queue>
using namespace std;
typedef long long int lli;
const long long int MaxN=300005;
const lli mod=1e9+7;
#define fst first
#define snd second
#define mp make_pair
const float pi=3.1415926535897932384626433832795028;
	lli mcd(lli a,lli b){
		if(a==0)return b;
		return mcd(b%a,a);
	}
	pair <lli,lli> par[MaxN];
	void solve(){
		lli N,M,i,j,p,q,res=0,llevo=0;
		cin>>N>>M;
		for(i=0;i<N;i++){
			cin>>p>>q;
			par[i].fst=p,par[i].snd=q;
		}
		sort(par,par+N);
		for(i=0;i<N;i++){
			if(par[i].snd+llevo>=M){
				res+=(M-llevo)*par[i].fst;
				break;
			}	
			else {
				llevo+=par[i].snd;
				res+=par[i].fst*par[i].snd;
			}
		}
		cout<<res;
	}
int main(){
	//cin.tie(0),ios_base::sync_with_stdio(0);
	lli i,t;
	t=1;
	for(i=1;i<=t;i++){
		solve();
	}
}
