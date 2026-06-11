#include <bits/stdc++.h>
 
using namespace std;
 
#define lli long long int
#define REP(i,s,l) for(lli i=s;i<l;i++)
#define DEBUG 0
#define INF (1LL<<50)
#define MOD 1000000007
 
signed main(){

	lli n;
	cin>>n;
	vector<lli> a(n);
	REP(i,0,n)cin>>a[i];

	lli ans = 0;
	lli before = a[n-1];
	lli now = before;
	if(a[0]!=0){
		cout<<-1<<endl;
		return 0;
	}
	for(lli i=n-2;i>=0;i--){
		if(DEBUG)cout<<"now="<<now<<" ans="<<ans<<endl;
		if(a[i]==now-1){

		}
		else if(a[i]>=now){
			ans+=before;
			now = a[i];
			before = a[i];
		}
		else{
			cout<<-1<<endl;
			return 0;
		}
		now = a[i];
	}
	ans += before;

	cout<<ans<<endl;

	return 0;
}