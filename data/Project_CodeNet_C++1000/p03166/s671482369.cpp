using namespace std;
#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#define w(x) int x;cin>>x;while(x--)

#define FIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

#define ll long long

void abc()
{
	FIO;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int mod = 1000000007;
map<int, vector<int>> adjlist;
vector<int> dp;


int go(int i) {
	if (dp[i] != -1) return dp[i];
	dp[i] = 0;
	for (auto j : adjlist[i]) {
		dp[i] = max(dp[i], go(j) + 1);
	}

	return dp[i];
}



int main()
{
	abc();
	int n, e;
	cin >> n >> e;
	dp.resize(n + 1, -1);
	while (e--) {
		int x, y;
		cin >> x >> y;
		adjlist[x].push_back(y);
	}

	int answer = 0;

	for (int i = 0; i <= n; i++) {
		answer = max(answer, go(i));
	}

	cout << answer;


}