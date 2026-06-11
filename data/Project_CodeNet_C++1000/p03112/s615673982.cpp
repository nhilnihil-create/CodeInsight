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

vector<lli> s,t;
signed main(){

	lli a,b,q;
	cin>>a>>b>>q;
	s.resize(a+2);
	t.resize(b+2);

	s[0]=-INF;
	s[a+1]=INF;
	t[0]=-INF;
	t[b+1]=INF;
	REP(i,0,a)cin>>s[i+1];
	REP(i,0,b)cin>>t[i+1];

	REP(i,0,q){
		lli x;
		cin>>x;

		vector<lli> v[2];
		auto itr = lower_bound(s.begin(),s.end(),x);
		v[0].push_back(*itr);
		v[0].push_back(*(itr-1));

		itr = lower_bound(t.begin(),t.end(),x);
		v[1].push_back(*itr);
		v[1].push_back(*(itr-1));

		lli ans=INF;
		for(auto e0:v[0])for(auto e1:v[1]){
			ans = min({ans,abs(x-e0)+abs(e0-e1),abs(x-e1)+abs(e1-e0)});
		}
		cout<<ans<<endl;
	} 
	return 0;
}