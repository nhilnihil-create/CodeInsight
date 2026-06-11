#include <bits/stdc++.h>

using namespace std;

#define lli long long int
#define REP(i,s,n) for(int i=s;i<n;i++)
#define MOD 1000000007
#define NUM 2520
#define INF (1LL<<50)
#define DEBUG 0
#define mp(a,b) make_pair(a,b)
#define SORT(V) sort(V.begin(),V.end())

signed main(){

	lli n;
	cin>>n;

	vector<lli> d(n);
	REP(i,0,n)cin>>d[i];

	sort(d.begin(),d.end());

	vector<lli> a;

	REP(i,0,n){
		lli next;
		if(i%2==0){
			next = d[i];
		}
		else{
			next = 24-d[i];
		}
		a.push_back(next);
	}

	a.push_back(0);
	sort(a.begin(),a.end());
	a.push_back(0);
	
	lli ans = 1000;
	REP(i,0,n){
		ans = min(ans,abs(a[i+1]-a[i]));
	}
	cout<<ans<<endl;


	return 0;
}