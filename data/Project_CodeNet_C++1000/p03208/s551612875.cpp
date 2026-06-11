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
	lli arr[MaxN];
	priority_queue < pair <lli,lli> > menor,mayor;
	void solve(){
		lli N,K,i,j,res=1e9,p,q;
		cin>>N>>K;
		pair <lli,lli> menori,mayori;
		for(i=0;i<N;i++){
			cin>>arr[i];
		}
		sort(arr,arr+N);
		for(i=0;i<=N-K;i++){
			//cout<<i<<" "<<i+K<<"\n";
			res=min(res,arr[i+K-1]-arr[i]);
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
