#include <bits/stdc++.h>
 
using namespace std;
 
#define lli long long int
#define lld long double
#define REP(i,s,n) for(lli i=s;i<n;i++)
#define RREP(i,s,n) for(lli i=s;i>=n;i--)
#define MOD 1000000007
#define NUM 2520
#define DEBUG 1
#define mp(a,b) make_pair(a,b)
#define SORT(V) sort(V.begin(),V.end())
#define PI (3.141592653589794)
#define INF (1LL<<50)

signed main(){

	lli a,b,k;
	cin>>a>>b>>k;

	REP(i,0,k){
		if(a%2)a--;
		lli tmp = a/2;
		a-=tmp;
		b+=tmp;
		i++;

		if(i>=k)continue;

		if(b%2)b--;
		tmp = b/2;
		b-=tmp;
		a+=tmp;
	}
	cout<<a<<" "<<b<<endl;

	return 0;
}