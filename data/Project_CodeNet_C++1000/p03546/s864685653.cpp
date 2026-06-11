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
#define Max(a,b) ((a) < (b) ? (b) : (a))
#define Min(a,b) ((a) > (b) ? (b) : (a))
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

int E(int a) {
	return (5 * a + 17) % 32;
}

int D(int a) {
	return (13 * (a - 17 + 32)) % 32;
}

void Cout(vector<int> A) {
	for (auto x : A) {
		char c = x + 'a';
		cout << c;
	}
	cout << endl;
}

int main() {
	int i, j, k;

	int N, M, K;
	int Q;

	int c[10][10];
	int C[10][10];
	map<int,int> A;
	const int INF = 1000000;
	int H, W;
	queue<int> que;
	int d[10] = { 0 };
	
	cin >> H >> W;
	rep(i, 0, 10) {
		rep(j, 0, 10) {
			cin >> c[i][j];
			C[i][j] = INF;
		}
		d[i] = c[i][1];
		if (i != 1)
			que.push(i);
	}


	while (!que.empty()) {
		int x = que.front();
		que.pop();
		rep(i, 0, 10) {
			if (x == i || i == 1)
				continue;
			if (d[i] > d[x] + c[i][x]) {
				d[i] = d[x] + c[i][x];
				que.push(i);
			}
		}

	}


	rep(i, 0, H) {
		rep(j, 0, W) {
			int a;
			cin >> a;
			if (a == -1)
				continue;
			A[a] ++;


		}
	}
	int ans = 0;
	for (auto x : A) {
		ans += x.second * d[x.first];
	}
	cout << ans;
	return 0;
}