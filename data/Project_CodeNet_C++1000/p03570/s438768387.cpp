#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<n;i++)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define FOR(i,m,n) for(int i=m;i<n;i++)
#define EPS (1e-7)
#define INF 1e9

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
int vx[]={0,1,0,-1};
int vy[]={1,0,-1,0};

int dx[]={0,1,0,-1,1,1,-1,-1};
int dy[]={1,0,-1,0,1,-1,1,-1};

const ll mod=1000000000+7;
const int MAX_N=1000;

int dp[1<<26];

int main(){
	string s;
	cin>>s;
	int n=s.size();
	int a[n+1];
	a[0]=0;
	a[1]=0|(1<<(s[0]-'a'));
	for(int i=2;i<=n;i++){
		a[i]=a[i-1]^(1<<(s[i-1]-'a'));
	}

	int opt[n+1];
	fill(opt,opt+n+1,INT_MAX);
	opt[0]=0;

	fill(dp,dp+(1<<26),INT_MAX);
	dp[a[0]]=0;

	int X[27];
	X[0]=0;
	for(int i=1;i<27;i++){
		X[i]=1<<(i-1);
	}

	for(int i=1;i<=n;i++){
		int minx=INT_MAX;
		for(int j=0;j<27;j++){
			minx=min(minx,dp[a[i]^X[j]]);
		}
		opt[i]=minx+1;

		dp[a[i]]=min(dp[a[i]],opt[i]);
	}

	cout<<opt[n]<<endl;
	return 0;
}