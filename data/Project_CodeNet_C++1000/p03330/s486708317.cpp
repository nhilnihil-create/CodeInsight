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

int D[31][31];
int c[510][510];
int cnt[31][3];
int main()
{
	int N, C;
	cin >> N >> C;
	for (int i = 0; i < C; i++) {
		for (int j = 0; j < C; j++) {
			cin >> D[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> c[i][j];
			c[i][j]--;
			cnt[c[i][j]][(i + j + 2) % 3]++;
		}
	}
	int ans = mod;
	for (int i = 0; i < C; i++) {
		for (int j = 0; j < C; j++) {
			for (int k = 0; k < C; k++) {
				if (i == j || j == k || k == i) continue;
				int cost = 0;
				for (int l = 0; l < C; l++) {
					cost += D[l][i] * cnt[l][0];
					cost += D[l][j] * cnt[l][1];
					cost += D[l][k] * cnt[l][2];
				}
				ans = min(ans, cost);
			}
		}
	}
	cout << ans << endl;
}