#include <bits/stdc++.h>

using namespace std;

#define lli long long int
#define REP(i,s,n) for(int i=s;i<n;i++)
#define MOD 1000000007
#define NUM 2520
#define INF (1LL<<50)
#define DEBUG 1
#define mp(a,b) make_pair(a,b)
#define SORT(V) sort(V.begin(),V.end())
#define PI (3.141592653589794)

signed main(){

	lli m,k;
	cin>>m>>k;

	if(m==1){
		if(k>=1)cout<<-1<<endl;
		else cout<<"0 0 1 1"<<endl;
		return 0;
	}

	lli n=1;
	REP(i,0,m)n*=2;

	if(k==0){
		REP(i,0,2*n)cout<<i/2<<" ";
		cout<<endl;
		return 0;
	}
	lli left = n-1;
	lli right = left-k;
	if(right<0){
		cout<<-1<<endl;
		return 0;
	}

	cout<<left<<" ";
	lli now = n-1;
	REP(i,0,n-2){
		while(now==left || now==right)now--;
		cout<<now<<" ";
		now--;
	}
	cout<<left<<" ";
	cout<<right<<" ";
	now = 0;
	REP(i,0,n-2){
		while(now==left || now==right)now++;
		cout<<now<<" ";
		now++;
	}
	cout<<right<<endl;
	return 0;
}