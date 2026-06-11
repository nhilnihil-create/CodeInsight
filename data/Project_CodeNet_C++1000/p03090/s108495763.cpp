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

	vector<pair<lli,lli>> v;
	lli n;

	cin>>n;

	for(lli i=1;i<=n;i++){
		for(lli j=i+1;j<=n;j++){
			if(n%2==0){
				if(j == n-i+1)continue;
			}
			else{
				if(j == n-i)continue;
			}
			v.push_back(make_pair(i,j));
		}
	}
	lli size = v.size();
	cout<<size<<endl;
	REP(i,0,size){
		cout<<v[i].first<<" "<<v[i].second<<endl;
	}

	return 0;
}