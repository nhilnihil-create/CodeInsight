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

lli n,m;
vector<lli> a;
lli data[9]={2,5,5,4,5,6,3,7,6};

#define MINUINF "("

//i本使ったときの dp[i]:桁数
string dp[10100];

void chmax(string &a,string b){
	if(a==MINUINF)a = b;
	else if(a.size()<b.size())a = b;
	else if(a.size()==b.size()){
		if(a<b)a=b;
	}
}

signed main(){

	cin>>n>>m;

	lli data[9]={2,5,5,4,5,6,3,7,6};
	a.resize(m);
	REP(i,0,m){
		cin>>a[i];
	}

	sort(a.begin(),a.end(),greater<lli>());

	REP(i,0,10100)dp[i]=MINUINF;
	dp[0]="";

	REP(i,0,m){
		REP(j,0,10090){
			if(dp[j]==MINUINF)continue;
			chmax(dp[j+data[a[i]-1]],dp[j]+(char)(a[i]+'0'));
	//		dp[j+data[a[i]]] = max(dp[j+data[a[i]]],dp[j]+(char)a[i]+'1');
		}
	}
	cout<<dp[n]<<endl;

	return 0;
}