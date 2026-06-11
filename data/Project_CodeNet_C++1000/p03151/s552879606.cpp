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
const long long int MaxN=500005;
const lli mod=1e9+7;
#define fst first
#define snd second
#define mp make_pair
const float pi=3.1415926535897932384626433832795028;
	lli mcd(lli a,lli b){
		if(a==0)return b;
		return mcd(b%a,a);
	}
	lli a[MaxN],b[MaxN];
	pair <lli,lli> par[MaxN];
	void solve(){
		lli N,i,j,p,q,tot=0,suma=0,res=0;
		cin>>N;
		for(i=0;i<N;i++){
			cin>>a[i];
		}
		for(i=0;i<N;i++){
			cin>>b[i];
		}
		vector <lli> cant;
		for(i=0;i<N;i++){
			if(a[i]<b[i])tot+=b[i]-a[i],res+=1;
			else {
				cant.push_back(a[i]-b[i]);
			}
		}	
		sort(cant.rbegin(),cant.rend());
		for(i=0;i<cant.size();i++){
			if(suma>=tot){
				cout<<res<<"\n";
				return;
			}
			suma+=cant[i];
			res+=1;
		}
		if(suma<=tot){
			cout<<"-1";
			return;
		}
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
