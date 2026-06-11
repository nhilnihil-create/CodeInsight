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
	cin>>n;

	vector<lli> a(n),b(n);
	REP(i,0,n)cin>>a[i];
	REP(i,0,n)cin>>b[i];

	lli sumA=0,sumB = 0;

	REP(i,0,n){
		if(a[i]<b[i]){
			sumA+=(b[i]-a[i])/2;
			if((b[i]-a[i])%2==1){
				sumA++;
				sumB++;
			}
		}
		else sumB += abs(a[i]-b[i]);
	}
	if(DEBUG)cout<<"sumA="<<sumA<<" sumB="<<sumB<<endl;
	if(sumB > sumA)cout<<"No"<<endl;
	else cout<<"Yes"<<endl;

	return 0;
}