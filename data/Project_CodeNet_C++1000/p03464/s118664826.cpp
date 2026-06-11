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
#define PI (3.141592653589794)

signed main(){

	lli k;
	cin>>k;
	vector<lli> a(k);
	REP(i,0,k)cin>>a[i];

	lli minA=2,maxA=2;
	if(a[k-1]!=2){
		cout<<-1<<endl;
		return 0;
	}

	for(lli i=k-1;i>=0;i--){
		if(DEBUG)cout<<minA<<" "<<maxA<<endl;
		if(minA>maxA){
			cout<<-1<<endl;
			return 0;
		}
		minA = ((minA-1)/a[i]+1)*a[i];
		maxA = ((maxA)/a[i]+1)*a[i]-1;
	}
	if(minA>maxA){
		cout<<-1<<endl;
		return 0;
	}
	cout<<minA<<" "<<maxA<<endl;

	return 0;
}