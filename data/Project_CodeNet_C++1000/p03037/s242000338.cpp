#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>

#define DIV 1000000007
#define TE 2e5
using namespace std;
using ll = long long;
using ldb = long double;

int main() {
	int N, M; cin >> N >> M;
	//vector<pair<int, int>> gate(M);
	int L = -1, R = 1e7;
	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		L = max(L, a), R = min(R, b);
	}
	cout << min(N, max(0,R - L + 1));

}
