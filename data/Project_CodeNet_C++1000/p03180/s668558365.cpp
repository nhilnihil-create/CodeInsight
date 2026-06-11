#include <cmath>
#include <cstdio>
#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <stack>
#include <fstream>
#include <queue>
#include <iomanip>
#include <iterator>
#include <map>
#include <unordered_map>
#include <set>
#include <numeric>
#define fast ios_base::sync_with_stdio(false)
#define mxn (ll)1e5
#define mod (ll)(1e9+7)
#define mod1 (ll)(998244353)
#define ll long long int
#define ld long double
#define vi vector<ll>
#define vvi vector<vi >
#define pi pair<ll,ll>
#define vvpi vector<vector<pi > >
#define vpi vector<pi >
#define vppi vector<pair<ll,pi > >
#define vs vector<string>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define pb push_back
#define eb emplace_back
#define mkp make_pair
#define fs first
#define se second
#define crz(v,n) v.clear(),v.resize(n+1,0)
#define print(v) for(ll it=0;it<v.size();it++) cout<<v[it]<<" ";cout<<endl
#define printp(v) for(ll it=0;it<v.size();it++) cout<<v[it].first<<" "<<v[it].second<<endl
using namespace std;
int bitcount(int x){
	int s=0;while(x) s++,x/=2;
	return s;
}
int main(){
	int i,j,n;cin>>n;int v[n][n];vi d(1<<n,0);
	for(i=0;i<n;i++) for(j=0;j<n;j++) cin>>v[i][j];
	for(i=1;i<(1<<n);i++){
		int x=bitcount(i);
		d[i]+=(d[i^(1<<(x-1))]);
		for(j=x-2;j>=0;j--){
			if((1<<j)&i) d[i]+=v[x-1][j];
		}
	}
	for(int k=0;k<(1<<n);k++){
		for(j=k;j;j=(j-1)&k){
			d[k]=max(d[k],d[j]+d[k-j]);
		}
	}cout<<d.back()<<endl;
	//	for(i=0;i<d.size();i++) cout<<i<<' '<<d[i]<<endl;
}
