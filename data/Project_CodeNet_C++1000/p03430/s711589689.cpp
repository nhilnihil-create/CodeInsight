#include<bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define umax(x,y) x=max(x,y)
#define umin(x,y) x=min(x,y)
#define ll long long 
#define ii pair<int,int>
#define iii pair<int,ii>
#define iiii pair<ii,ii>
#define sz(x) ((int) x.size())
#define orta ((bas+son)/2)
#define all(x) x.begin(),x.end()
#define pw(x) (1<<(x))
#define inf 1000000005
#define MOD 924844033 
#define N 100005
#define M 1000003
#define LOG 20
#define KOK 250
#define EPS 0.0000001
using namespace std;

int n,k;
bool vis[305][305][305];
int dp[305][305][305];
char s[305];

int solve(int l,int r,int rem) {

	if(rem<0) return -inf;

	if(l>=r) return (l==r);

	bool& v=vis[l][r][rem];
	int& res=dp[l][r][rem];

	if(v) return res;

	v=1;

	if(s[l]==s[r]) umax(res,solve(l+1,r-1,rem)+2);

	umax(res,max(solve(l+1,r,rem),solve(l,r-1,rem)));

	umax(res,solve(l+1,r-1,rem-1)+2);

	return res;

}

int main() {

	scanf("%s %d",s+1,&k);

	n=strlen(s+1);

	printf("%d",solve(1,n,k));

}