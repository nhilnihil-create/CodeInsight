#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <numeric>
#include <queue>
#include <numeric>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <map>
#include <functional>
#include <limits>
#include <set>
#include <stack>
#define rep(i,a,b) for((i)=a;i<(int)(b);i++)

#define AAA (1000000007) 


using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pairII;


ll gcd(ll a, ll b) {
	if (b == 0)return a;
	return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}
ll powD(ll a, ll b) {
	ll ans = 1;
	a %= AAA;
	for (int i= 0; i <b; i++)
	{
		ans *= a;
		ans %= AAA;
	}
	return ans;
}


int main(){
	int i, j, k;

	int N, M, K;

	cin >> N;
	vector<int> c;
	vector<int> A[10001];
	int B[10001] = { 0 };
	rep(i, 0, N - 1) {
		int a, b;
		cin >> a >> b;
		A[a].push_back(b);
		A[b].push_back(a);
	}
	ll sum = 0;
	rep(i, 0, N) {
		int a;
		cin >> a;
		sum += a;
		c.push_back(a);
	}
	sort(c.rbegin(), c.rend());
	sum -= c[0];

	stack<int> Q;
	Q.push(1);
	B[1] = c[0];
	for (i = 1; i < N;) {
		int x = Q.top();
		Q.pop();
		for (auto y : A[x]) {
			if (B[y] != 0)
				continue;

			B[y] = c[i++];
			Q.push(y);

		}


	}
	cout << sum << endl;
	rep(i, 1, N + 1) {
		cout << B[i] << " ";
	}
	return 0;
}