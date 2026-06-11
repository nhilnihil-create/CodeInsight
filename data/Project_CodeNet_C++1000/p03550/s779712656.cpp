#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N = 2009;
int N, Z, W;
int a[MAX_N];
int dp[MAX_N][2];

int go(int x, int turn)
{
    int& sc = dp[x][turn];
    if(sc!=-1) return sc;
    if(turn){
        sc = abs(a[N]-a[x]);
        for(int i=x+1;i<N;++i) sc=min(sc, go(i, 0));
        return sc;
    }else{
        sc = abs(a[N]-a[x]);
        for(int i=x+1;i<N;++i) sc=max(sc, go(i, 1));
    }
    return sc;
}

void solve()
{
	int ans = abs(a[N]-W); // x can achieve
	memset(dp,-1,sizeof(dp));
	for(int i=1;i<N;++i){
		ans=max(ans, go(i,1));
	}
	cout<<ans<<'\n';
}

int main()
{
	cin >> N >> Z >> W;
	for(int i=1;i<=N;++i) cin >> a[i];
	solve();
	return 0;
}