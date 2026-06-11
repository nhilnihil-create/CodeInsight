#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<map>
#include<tuple>
#include<algorithm>
#include<cmath>
#include<limits>
#include<set>
#include<deque>
#include<queue>
#include<stack>
using namespace std;
#define int long long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define dup(x,y) (((x)+(y)-1)/(y))
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef pair<int, int>P;
const int MOD = 1e9 + 7;
//const int MOD = 998244353;
const int INF = 1e18;
const long double PI = (acos(-1));


vector<int> Eratosthenes(int N) {
	vector<bool>is_prime(N + 1, true);
	vector<int>P;
	for (int i = 2; i <= N; i++) {
		if (is_prime[i]) {
			for (int j = 2 * i; j <= N; j += i)is_prime[j] = false;
			P.emplace_back(i);
		}
	}
	return P;
}


signed main() {
	int N;
	cin >> N;
	vector<int>P = Eratosthenes(55555);
	vector<int>ans(N);
	int cursor = 0;
	rep(i, N) {
		while (1) {
			if (P[cursor] % 5 == 1) {
				ans[i] = P[cursor];
				cursor++;
				break;
			}
			cursor++;
		}
	}
	rep(i, N) {
		cout << ans[i];
		if (i != N - 1)cout << " ";
	}
}