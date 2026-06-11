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
 
signed main(){
 
	lli n;
	cin>>n;
 
	vector<lli> d(n);
	REP(i,0,n){
		cin>>d[i];
		if(d[i]>12)d[i] = 24-d[i];
	}
 
	sort(d.begin(),d.end());
 
	vector<lli> ans;
 
	REP(i,0,n){
		if(i%2==0)ans.push_back(d[i]);
		else ans.push_back(24-d[i]);
	}
 
	sort(ans.begin(),ans.end());
 
	lli cnt = min(ans[0],24LL-ans[n-1]);
	REP(i,1,n){
		cnt = min(abs(ans[i]-ans[i-1]),cnt);
	}
	cout<<cnt<<endl;
 
	return 0;
}