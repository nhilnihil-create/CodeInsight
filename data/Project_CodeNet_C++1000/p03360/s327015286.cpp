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
	lli pot[20];
	void solve(){
		lli A,B,C,K,res=0,maxi=0,i;
		cin>>A>>B>>C>>K;
		maxi=max(A,max(B,C));		
		pot[0]=1;
		for(i=1;i<12;i++)pot[i]=pot[i-1]*2;
		res=A+B+C-maxi+(maxi*pot[K]);
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
