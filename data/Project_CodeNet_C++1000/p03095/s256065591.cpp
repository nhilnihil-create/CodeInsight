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

#define P pair<lli,lli>

signed main(){

	map<char,lli> cnt;
	lli n;
	cin>>n;

	REP(i,0,n){
		char tmp;
		cin>>tmp;
		cnt[tmp]++;
	}

	lli ans = 1;
	for(auto e:cnt){
		ans *= (e.second+1);
		ans%=MOD;
	}

	ans -= 1;
	if(ans<0)ans+=MOD;

	cout<<ans<<endl;


	return 0;
}