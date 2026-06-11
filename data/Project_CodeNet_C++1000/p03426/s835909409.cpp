#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<deque>
using namespace std;
#define ll long long
const int mod = 1000000007;
const ll INF = 1000000000000000000;

int A[310][310];
int x[100010], y[100010];
int d[100010];
int main()
{
	int H, W, D;
	cin >> H >> W >> D;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> A[i][j];
			x[A[i][j]] = j + 1;
			y[A[i][j]] = i + 1;
		}
	}
	for (int i = 1 + D; i <= H * W; i++) {
		d[i] = d[i - D] + abs(x[i] - x[i - D]) + abs(y[i] - y[i - D]);
	}
	int Q;
	cin >> Q;
	while (Q--) {
		int L, R;
		cin >> L >> R;
		cout << d[R] - d[L] << endl;
	}
}
