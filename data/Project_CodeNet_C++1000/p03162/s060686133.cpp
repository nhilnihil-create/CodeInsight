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
vector<vector<int>> dp;
vector<vector<int>> v;


int go( int i, int flag) {



	if (i == v.size() ) return 0;
	if (dp[i][flag] != -1) return dp[i][flag];



	int a = v[i][0] + go(i + 1, 1);
	int b = v[i][1] + go(i + 1, 2);
	int c = v[i][2] + go(i + 1, 3);



	if (flag == 0) {
		return dp[i][flag] = max({a, b, c});
	}
	else if (flag == 1) {
		return dp[i][flag] = max(b, c);
	}
	else if (flag == 2) {
		return dp[i][flag] = max(a, c);
	}
	else {
		return dp[i][flag] = max(a, b);
	}



}



int main()
{
	abc();


	int n;
	cin >> n ;
	v.resize(n, vector<int>(3));
	dp.resize(n, vector<int>(4, -1));

	for (int i = 0; i < n; i++) cin >> v[i][0] >> v[i][1] >> v[i][2];

	cout << go(0, 0) << endl;


}