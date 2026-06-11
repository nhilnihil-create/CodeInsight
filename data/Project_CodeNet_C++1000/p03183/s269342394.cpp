#include <bits/stdc++.h>

using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;
typedef pair<int,int> PI; 
typedef pair<LL,LL> PLL;
typedef unsigned long long ULL;
typedef pair<double,double> PD;

#define FOR(x, b, e) for(int x = b; x<= (e); x++)
#define FORD(x, b, e) for(int x = b; x>= (e); x--)
#define REP(x, n) for(int x = 0; x<(n); ++x)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(x) ((int)(x).size())

#define PB push_back
#define IN insert
#define ST first
#define ND second
#define INF 2000000011
#define MOD 1000000007

#define MAXS 20123

LL dp[MAXS];

struct S{
	int w,v,s;
	void read(){
		cin>>w>>s>>v;
	}	
};

bool comp_(S s1,S s2){
	return s1.w+s1.s<s2.s+s2.w;
}

int n;

int main(){	//TODO: ogarnac exchanging arguments
	
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>n;
	
	vector<S> zb(n);
	
	REP(I,n)
		zb[I].read();
	
	sort(ALL(zb),comp_);
	
	for(auto block : zb){
		FORD(k,block.s,0)
			dp[k+block.w]=max(dp[k+block.w],dp[k]+block.v);
	}
	
	LL odp=0;
	REP(i,MAXS)
		odp=max(odp,dp[i]);
	
	cout<<odp;
	
	
	return 0;
}


