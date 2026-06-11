#include <bits/stdc++.h>
 
using namespace std;
 
#define lli long long int
#define REP(i,s,n) for(int i=s;i<n;i++)
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

	vector<lli> a(n);
	lli cnt=0;

	REP(i,0,n){
		cin>>a[i];
		if(i!=0){
			if(a[i]==a[i-1]){
				a[i] = INF-cnt;
				cnt++;
			}
		}
	}

	cout<<cnt<<endl;




	return 0;
}