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
	lli arr[MaxN];
	lli cub1[MaxN],cub2[MaxN];
	lli vis1[MaxN],vis2[MaxN];
	vector < pair <lli,lli> > val1,val2;
	void solve(){
		lli N,i,j,res=0,p=0,q=0,r1=1e9,r2=1e9;
		cin>>N;
		for(i=0;i<N;i++){
			cin>>arr[i];
			if(i%2==0){
				cub1[arr[i]]+=1;
				p+=1;
			}
			else cub2[arr[i]]+=1,q+=1;
		}
		for(i=0;i<N;i++){
			if(i%2==0){
				if(vis1[arr[i]])continue;
				vis1[arr[i]]=1;
				r1=min(p-cub1[arr[i]],r1);
				val1.push_back(mp(p-cub1[arr[i]],arr[i]));
			}
			else {
				if(vis2[arr[i]])continue;
				vis2[arr[i]]=1;
				r2=min(q-cub2[arr[i]],r2);
				val2.push_back(mp(p-cub2[arr[i]],arr[i]));
			}
		}
		sort(val1.begin(),val1.end());
		sort(val2.begin(),val2.end());
		if(val1[0].snd!=val2[0].snd)cout<<val1[0].fst+val2[0].fst;
		else {
			if(val1.size()==1&&val2.size()==1){
				cout<<N/2;
			}
			else cout<<min(val1[0].fst+val2[1].fst,val1[1].fst+val2[0].fst);
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