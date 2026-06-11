#include <bits/stdc++.h>
 
using namespace std;
 
#define lli long long int
#define lld long double
#define REP(i,s,n) for(lli i=s;i<n;i++)
#define RREP(i,s,n) for(lli i=s;i>=n;i--)
#define MOD 1000000007
#define NUM 2520
#define DEBUG 0
#define mp(a,b) make_pair(a,b)
#define SORT(V) sort(V.begin(),V.end())
#define PI (3.141592653589794)
#define INF (1LL<<50)

signed main(){

	lli k;
	cin>>k;
	vector<lli> a(k);
	REP(i,0,k)cin>>a[i];

	lli minNum=2,maxNum=2;

/*
	if(a[k-1]!=2){
		cout<<-1<<endl;
		return 0;
	}
	*/

	for(lli i=k-1;i>=0;i--){
		if(DEBUG)cout<<"minNum="<<minNum<<" maxNum="<<maxNum<<endl;
		
		if(maxNum<a[i]){
			cout<<-1<<endl;
			return 0;
		}
		if(minNum>maxNum){
			cout<<-1<<endl;
			return 0;
		}
		
		maxNum = ((maxNum)/a[i]+1)*a[i]-1;
		minNum = ((minNum-1)/a[i]+1)*a[i];
	}
	if(minNum>maxNum){
		cout<<-1<<endl;
		return 0;
	}

	cout<<minNum<<" "<<maxNum<<endl;

	return 0;
}