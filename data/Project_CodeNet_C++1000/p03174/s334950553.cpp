#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>
#include<tuple>

#define DIV 1000000007
using namespace std;
using ll = long long;
using ldb = long double;

vector<vector<int>> rlt;
vector<ll> dp;
int N;

ll ff(ll n) {
	if(n<100)cout << "n=" << n << endl;
	if (dp[n] != 0) return dp[n];
	if (n == 0)return dp[n] = 1;
	int num = 0;
	for (int i = 0; i < N; i++) {
		if (n & (1 << i))num++;
	}

	int temp;
	for (int i = 0; i < N; i++) {
		if ((1 << i) & n) {
			if (rlt[num-1][i]) {
				temp = n ^ (1 << i);
				dp[n] += ff(temp);
				dp[n] %= DIV;
			}
		}
	}

	return dp[n]%=DIV;
}


int main() {
	cin >> N;
	rlt = vector<vector<int>>(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> rlt[i][j];
		}
	}

	ll mx = 1 << N;
	dp = vector<ll>(mx);
	dp[0] = 1;
	for (ll i = 0; i < mx - 1; i++) {
		int num = 0;
		for (ll k = 0; k < N; k++) {
			if (i & (1 << k))num++;
		}

		for (ll j = 0; j < N; j++) {
			if ((!(i & (1 << j))) && rlt[num][j]) {
				dp[i ^ (1 << j)] += dp[i];
				dp[i ^ (1 << j)] %= DIV;
			}
		}

	}

	cout << dp[mx - 1] << endl;
}

