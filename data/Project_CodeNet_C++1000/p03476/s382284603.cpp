#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#include <stdio.h>
#include <math.h>
using namespace std;
typedef long long int lli;
const long long int MaxN=200005;
const lli mod=1e9+7;
#define fst first
#define snd second
#define mp make_pair
const float pi=3.1415926535897932384626433832795028;
	lli mcd(lli a,lli b){
		if(a==0)return b;
		return mcd(b%a,a);
	}
	lli criba[MaxN];
	lli pre[MaxN];
	void solve(){
		lli N,Q,i,j,l,r,p;
		N=120000;
		for(i=2;i<=N;i++){
			if(criba[i])continue;
			for(j=i*2;j<=MaxN;j+=i){
				criba[j]=1;
			}
		}
		for(i=3;i<N;i++){
			p=0;
			if(!criba[i]&&(!criba[(i+1)/2]))p=1;
			//if(p==1&&i<100)cout<<i<<"\n";
			pre[i]=pre[i-1]+p;
		}
		cout<<"\n";
		cin>>Q;
		while(Q--){
			cin>>l>>r;
			cout<<pre[r]-pre[l-1]<<"\n";
		}
	}
int main(){
	cin.tie(0),ios_base::sync_with_stdio(0);
	lli i,t;
	t=1;
	for(i=1;i<=t;i++){
		solve();
	}
}