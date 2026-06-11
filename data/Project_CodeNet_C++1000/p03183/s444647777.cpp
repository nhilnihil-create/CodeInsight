#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
using namespace std;
int n,dp[1009][10009];
pair <pair<int,int>,int> v[1009];
int f(int i,int c){
	if(i==n)return 0;
	if(dp[i][c]!=-1)
		return dp[i][c];
	dp[i][c]=f(i+1,c);
	if(v[i].f.f<=c)
		dp[i][c]=max(dp[i][c],v[i].s+f(i+1,min(c-v[i].f.f,v[i].f.s)));
	return dp[i][c];
}
int32_t main(){
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> v[i].f.f >> v[i].f.s >> v[i].s;
		v[i].f.f+=v[i].f.s;
	}
	sort(v,v+n);
	reverse(v,v+n);
	for(int i=0;i<n;i++)
		v[i].f.f-=v[i].f.s;
	memset(dp,-1,sizeof(dp));
	int m=0;
	for(int i=0;i<n;i++)
		m=max(v[i].s+f(i+1,v[i].f.s),m);
	cout << m << endl;
}
