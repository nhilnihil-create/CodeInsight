#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#include <stdio.h>
#include <math.h>
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
	int arr[MaxN];
	pair <int,int> par[MaxN];
	void solve(){
		lli N,i,j,p,q,res=0;
		N=5;
		for(i=0;i<N;i++){
			cin>>arr[i];
			par[i].fst=((10-arr[i]%10))%10;
			par[i].snd=arr[i];
		}
		sort(par,par+N);
		for(i=0;i<N;i++){
			res+=par[i].snd;
			//cout<<par[i].fst<<" "<<par[i].snd<<"\n";
			if(i==N-1)break;
			res+=par[i].fst;
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
