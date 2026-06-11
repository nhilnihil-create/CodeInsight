#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>
#include<math.h>

#define DIV 1000000007
using namespace std;
using ll = long long;

int main(void) {
	int N;
	cin >> N;

	vector<int> C(N);
	map<int, vector<int>> posi;
	for (int i = 0; i < N; i++) {
		cin >> C[i];
		posi[C[i]].push_back(i);
	}

	vector<ll> dp(N + 1);
	dp[0] = 1;
	for (int i = 1; i <= N; i++) {
		dp[i] = dp[i - 1];
		int id = lower_bound(posi[C[i-1]].begin(), posi[C[i-1]].end(), i)- posi[C[i-1]].begin()-1;
		//cout << "id=" << id << endl;
		if (id != 0) {
			if (posi[C[i - 1]][id - 1] + 1 != i-1) {
				//cout << posi[C[i - 1]][id - 1] << " " << i-1 << endl;
				dp[i] += dp[posi[C[i - 1]][id - 1]+1];
			}
		}
		dp[i] %= DIV;
	}
	/*
	for (int i = 1; i <= N; i++) {
		printf("dp[%d]=", i);
		cout << dp[i] << endl;
	}
	*/
	cout << dp[N] << endl;
}
