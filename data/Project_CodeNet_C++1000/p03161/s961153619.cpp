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
vector<int> dp;
vector<int> v;


int go( int i, int k) {


	if (i == v.size() - 1) return 0;
	if (dp[i] != -1) return dp[i];

	int x = INT_MAX ;


	for (int j = 1; j <= k; j++) {
		if (i + j < v.size()) {
			int y = abs(v[i] - v[i + j]) + go(i + j, k);
			x = min(x, y);
		}
	}

	return dp[i] = x;



}



int main()
{
	abc();


	int n; int k;
	cin >> n >> k;
	v.resize(n);
	dp.resize(n, -1);

	for (int i = 0; i < n; i++) cin >> v[i];

	cout << go(0, k) << endl;










}