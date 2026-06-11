#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
const int INF = 1e9;
#define PII pair<int, int>
int rock[maxn];
int dp[maxn];
void do_dp(int n){
	priority_queue<PII, vector<PII>, greater<PII>> pq;
	pq.push(make_pair(0, 1));
	int rh, rn;
	while(!pq.empty()){
		tie(rh, rn) = pq.top(); pq.pop();
		if(dp[rn] != 1e9) continue;
		dp[rn] = rh;
		if(rn + 1 <= n) pq.push(make_pair(rh + abs(rock[rn+1] - rock[rn]), rn + 1));
		if(rn + 2 <= n) pq.push(make_pair(rh + abs(rock[rn+2] - rock[rn]), rn + 2));
	}
}
int main(int argc, char const *argv[])
{
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &rock[i]);
	}

	fill(dp, dp + n + 1, INF);

	do_dp(n);
	printf("%d\n", dp[n]);

	return 0;
}