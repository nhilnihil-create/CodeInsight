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
#define fast ios_base::sync_with_stdio(false)
#define mxn (ll)(305)
#define mod (ll)(1e9+7)
#define mod1 (ll)(998244353)
#define ll long long
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
ld d[mxn][mxn][mxn];int c[4];
int main(){
	int n,i,j,k;cin>>n;for(i=0;i<n;i++) cin>>j,c[j]++;
	for(k=0;k<mxn;k++){
		for(j=0;j<mxn;j++){
			for(i=0;i<mxn;i++){
				if(!(i+j+k)||i+j+k>n) continue;
				ld p0=1.0*n/(i+j+k);
				ld p1=(1.0*i/(i+j+k));
				ld p2=(1.0*j/(i+j+k));
				ld p3=(1.0*k/(i+j+k));
				if(i) d[i][j][k]+=d[i-1][j][k]*p1;
				if(j) d[i][j][k]+=d[i+1][j-1][k]*p2;
				if(k) d[i][j][k]+=d[i][j+1][k-1]*p3;
				d[i][j][k]+=p0;
			}
		}
	}printf("%.10Lf\n",d[c[1]][c[2]][c[3]]);
}
