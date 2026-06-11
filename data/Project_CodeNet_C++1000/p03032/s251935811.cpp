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


signed main() {
	int N, K;
	cin >> N >> K;
	vector<int>V(N);
	rep(i, N)cin >> V[i];
	int sum = 0;
	rep(i, N)sum += V[i];
	vector<int>d(N + 1);
	d[0] = 0;
	rep(i, N)d[i + 1] += d[i];
	int ans = 0;
	for (int i = 1; i <= K; i++) {  // 操作を行う回数
		for (int j = 0; j <= i / 2; j++) {  // 詰める操作を行う回数
			int take = i - j;  // 取り出す回数
			if (take < j)continue;
			if (take > N)continue;
			for (int k = 0; k < N; k++) {
				priority_queue<int, vector<int>, greater<int>>q;
				int sum = 0;
				bool isOK = false;
				for (int l = 0; l < take; l++) {
					sum += V[(k + l) % N];
					q.push(V[(k + l) % N]);
					if ((k + l) % N == 0 || (k + l) % N == N - 1)isOK = true;
				}
				if (!isOK)continue;
				for (int l = 0; l < j; l++) {
					sum -= q.top();
					q.pop();
				}
				chmax(ans, sum);
			}
		}

	}
	cout << ans << endl;
}