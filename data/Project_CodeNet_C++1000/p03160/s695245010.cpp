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


int go( int i) {

	if (i >= v.size() ) return INT_MAX / 2;
	if (i == v.size() - 1) return 0;
	if (dp[i] != -1) return dp[i];

	int x = INT_MAX / 2, y = INT_MAX / 2;

	if (i + 1 < v.size()) {
		x = abs(v[i] - v[i + 1]) + go(i + 1);
	}
	if (i + 2 < v.size()) {
		y = abs(v[i] - v[i + 2]) + go(i + 2);
	}

	return dp[i] = min(x, y);



}



int main()
{
	abc();


	int n;
	cin >> n;
	v.resize(n);
	dp.resize(n, -1);

	for (int i = 0; i < n; i++) cin >> v[i];

	cout << go(0) << endl;








}