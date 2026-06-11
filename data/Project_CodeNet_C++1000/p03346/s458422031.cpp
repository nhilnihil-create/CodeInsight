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

int main() {
	int i, j, k;

	int N, M, K;

	int P[200000];
	int A[200001];
	cin >> N;
	rep(i, 0, N) {
		int a;
		cin >> a;
		P[i] = a;
		A[a] = i;
	}

	int ans = 0;
	rep(i, 0, N) {
		int x = P[i];
		if (A[x] == -1)
			continue;
		A[x] = -1;
		int score = 1;
		int pos = i;
		for (j = x+1; j <= N; j++) {
			if (A[j] == -1) {
				break;
			}
			else if (A[j] > pos) {
				score++;
				pos = A[j];
				A[j] = -1;
			}
			else {
				break;
			}


		}
		ans = max(ans, score);
	}
	cout << N - ans;

	return 0;
}