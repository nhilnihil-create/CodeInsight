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
	lli pre0[MaxN],pre1[MaxN],suf0[MaxN],suf1[MaxN];
	void solve(){
		lli N,i,j,p=0,q=0,res=1e9,negro=0;
		string bin;
		cin>>N;
		cin>>bin;
		bin='0'+bin;
		pre0[0]=pre1[0]=suf0[N+1]=suf1[N+1]=0;
		for(i=1;i<=N;i++){
			p=q=0;
			if(bin[i]=='#'){
				p=1;
			}
			else q=1;
			pre0[i]=pre0[i-1]+q;
			pre1[i]=pre1[i-1]+p;
		}
		for(i=N;i>=1;i--){
			p=q=0;
			if(bin[i]=='#'){
				p=1;
			}
			else q=1;
			suf0[i]=suf0[i+1]+q;
			suf1[i]=suf1[i+1]+p;
		}
		for(i=1;i<=N;i++){
			p=pre1[i]+suf0[i+1];
			res=min(res,p);
		}
		res=min(pre1[N],res);
		res=min(pre0[N],res);
		cout<<res<<"\n";
	}
int main(){
	//cin.tie(0),ios_base::sync_with_stdio(0);
	lli i,t;
	t=1;
	for(i=1;i<=t;i++){
		solve();
	}
}