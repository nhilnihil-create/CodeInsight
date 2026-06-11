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

	lli k;
	cin>>k;

	vector<lli> a(k);
	REP(i,0,k)cin>>a[i];

	lli small=2;
	lli large=2;

	for(lli i=k-1;i>=0;i--){
		if(small>large){
			cout<<-1<<endl;
			return 0;
		}
		lli nextLarge = (large/a[i] + 1)*a[i] -1;
		lli nextSmall = (small/a[i] + (small%a[i]!=0) )*a[i];

		large = nextLarge;
		small = nextSmall;

		if(DEBUG)cout<<"i="<<i<<" large="<<large<<" smal="<<small<<endl;
	}
	if(small>large){
		cout<<-1<<endl;
		return 0;
	}

	cout<<small<<" "<<large<<endl;

	return 0;
}