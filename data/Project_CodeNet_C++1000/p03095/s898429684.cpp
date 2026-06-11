#include <bits/stdc++.h>

using namespace std;

#define lli long long int
#define REP(i,s,n) for(int i=s;i<n;i++)
#define RREP(i,s,n) for(lli i=s;i>=n;i--)
#define MOD 1000000007
#define NUM 2520
#define DEBUG 0
#define mp(a,b) make_pair(a,b)
#define SORT(V) sort(V.begin(),V.end())
#define PI (3.141592653589794)
#define INF (1LL<<50)

signed main(){

	lli n;
	string s;
	cin>>n>>s;

	map<lli,lli> d;

	REP(i,0,n){
		d[s.at(i)-'a']++;
	}

	lli sum=1;
	REP(i,0,26){
		if(d[i]==0)continue;
		sum *= (d[i]+1);
		sum %= MOD;
	}

	cout<<(sum+MOD-1)%MOD<<endl;


	return 0;
}