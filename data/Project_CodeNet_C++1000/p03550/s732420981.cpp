#include <bits/stdc++.h>

using namespace std;

#define lli long long int
#define REP(i,s,n) for(int i=s;i<n;i++)
#define MOD 1000000007
#define NUM 2520
#define INF (1LL<<50)
#define DEBUG 1
#define mp(a,b) make_pair(a,b)
#define SORT(V) sort(V.begin(),V.end())
#define PI (3.141592653589794)

signed main(){

	lli n,z,w;
	cin>>n>>z>>w;

	vector<lli> a(n);
	REP(i,0,n)cin>>a[i];
 
	if(n==1){
		cout<<abs(a[0]-w)<<endl;
		return 0;
	}
 
	cout<<max(abs(a[n-1]-w),abs(a[n-1]-a[n-2]))<<endl;

	return 0;
}