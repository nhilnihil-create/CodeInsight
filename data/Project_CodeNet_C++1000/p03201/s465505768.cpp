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

	map<lli,lli> m;
	REP(i,0,n){
		lli a;
		cin>>a;
		m[-a]++;
	}
	lli sum=0;

	for(lli i=0;i<n && !m.empty();i++){
		lli now = -m.begin()->first;
		if(DEBUG)cout<<"now="<<now<<endl;
		m[-now]--;
		if(m[-now]==0)m.erase(-now);

		lli bi=1;
		while(bi<=now)bi*=2;
		lli target = bi-now;
		if(DEBUG)cout<<"target="<<target<<endl;
		if(m.count(-target)){
			sum++;
			m[-target]--;
			if(m[-target]==0)m.erase(-target);
		}
	}

	cout<<sum<<endl;

	return 0;
}