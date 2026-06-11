#include <bits/stdc++.h>
 
using namespace std;
 
#define lli long long int
#define lld long double
#define REP(i,s,n) for(lli i=s;i<n;i++)
#define RREP(i,s,n) for(lli i=s;i>=n;i--)
#define MOD 1000000007
#define NUM 2520
#define DEBUG 1
#define mp(a,b) make_pair(a,b)
#define SORT(V) sort(V.begin(),V.end())
#define PI (3.141592653589794)
#define INF (1LL<<50)

lli a[400][400];
bool vis[100100];
lli sum[100100];
lli h,w,d;
map<lli,pair<lli,lli>> dd;

signed main(){
	cin>>h>>w>>d;

	REP(i,0,h)REP(j,0,w){
		cin>>a[i][j];
		dd[a[i][j]] = mp(i,j);
	}
	for(lli i=1;i<=h*w;i++){
		sum[i+d] = sum[i] + abs(dd[i].first-dd[i+d].first)+abs(dd[i].second-dd[i+d].second);
	}

	lli q;
	cin>>q;
	REP(i,0,q){
		lli l,r;
		cin>>l>>r;
		cout<<sum[r]-sum[l]<<endl;
	}

	return 0;
}