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
#define max(a,b) ((a) < (b) ? (b) : (a))
#define min(a,b) ((a) > (b) ? (b) : (a))
#define AAA (1000000007)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;



ll gcd(ll a, ll b) {
	if (b == 0)return a;
	return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}

int Get(string S) {
	int sum = 0;
	for (int i = 0; i < S.size() - 1; ++i) {
		if (S[i] == 'A' && S[i + 1] == 'B') {
			sum++;
		}
	}
	return sum;
}
int main() {
	int i, j, k;
	//ll N, M, K;
	int N, M, K;

	int A = 0, B = 0;
	int BA = 0;

	string S[10000];
	cin >> N;
	int sum = 0;
	rep(i, 0, N) {
		cin >> S[i];
		if (S[i].front() == 'B' && S[i].back() == 'A') {
			BA++;
		}
		else if (S[i].front() == 'B')
			B++;
		else if (S[i].back() == 'A')
			A++;

		sum += Get(S[i]);
	}

	if (BA > 0) {
		sum += BA - 1;
		if (A > 0) {
			A--;
			sum++;
		}
		if (B > 0) {
			B--;
			sum++;
		}
	}
	sum += min(A, B);
	cout << sum;
	return 0;

}
