#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N = 2e5+10;
int N;
int h[MAX_N];
int a[MAX_N];
ll V[MAX_N+1];
ll dp[MAX_N+1];

void update(int i, ll x)
{
	while(i<=MAX_N){
		V[i]=max(V[i],x);
		i+=(i&-i);
	}
}

ll query(int i)
{
	ll res = 0;
	while(i>0){
		res =max(res, V[i]);
		i -= (i&-i);
	}
	return res;
}

void solve()
{
	for(int i=1;i<=N;++i){
		dp[i]=max(dp[i], query(h[i]-1)+a[i]);
		update(h[i],dp[i]);
	}
	cout << *max_element(dp+1, dp+N+1) << '\n';
}

int main()
{
	cin >> N;
	for(int i=1;i<=N;++i) cin >> h[i];
	for(int i=1;i<=N;++i) cin >> a[i];
	solve();
	return 0;
}