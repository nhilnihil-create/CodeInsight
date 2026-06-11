#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#include<climits>
#include<string>
#include<set>
#include<map>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i=0;i<((int)(n));i++)
#define reg(i,a,b) for(int i=((int)(a));i<=((int)(b));i++)
#define irep(i,n) for(int i=((int)(n))-1;i>=0;i--)
#define ireg(i,a,b) for(int i=((int)(b));i>=((int)(a));i--)
typedef long long int lli;
typedef pair<int,int> mp;
#define fir first
#define sec second
#define IINF INT_MAX
#define LINF LLONG_MAX
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#define pque(type) priority_queue<type,vector<type>,greater<type> >
#define memst(a,b) memset(a,b,sizeof(a))
#define iter(v,ite) for(auto ite=(v).begin();ite!=(v).end();ite++)
#define mimunum(v,x) distance((v).begin(),lower_bound((v).begin(),(v).end(),x))

char S[3005];
lli dp[3005][3005];
#define MOD (1000000007LL)

int main(void){
	int n;
	scanf("%d%s",&n,S);
	rep(i,n)dp[0][i] = 1;
	rep(i,n-1){
		lli s = 0;
		rep(j,n-i)s = (s + dp[i][j])%MOD;
		lli ns = 0;
		rep(j,n-i-1){
			ns = (ns + dp[i][j]) % MOD;
			if(S[i]=='>')dp[i+1][j] = (s - ns + MOD) % MOD;
			if(S[i]=='<')dp[i+1][j] = ns;
		}
	}
	printf("%lld\n",dp[n-1][0]);
	return 0;
}