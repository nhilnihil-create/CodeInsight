#include <bits/stdc++.h>

using namespace std;

#define lli long long int
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

	lli data[10]={0};

	REP(i,0,4){
		lli a;
		cin>>a;
		data[a]++;
	}
	if(data[1]==1 && data[9]==1&&data[7]==1&&data[4]==1){
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO"<<endl;
	}

	return 0;
}
