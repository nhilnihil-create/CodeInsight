// Comment
// Dp[k][i] = k bit 까지 생각 했을 때, (x&i) == x 인 x 집합
// Dp[k][i] = Dp[k-1][i] U Dp[k-1][i - (1<<k) when ((1<<k) & i == (1<<k))

#include <bits/stdc++.h>

using namespace std;

#define SZ(v) ((int)(v).size())
#define ALL(v) (v).begin(),(v).end()
#define one first
#define two second
using ll = long long;
using pi = pair<int, int>;
const int INF = 0x3f3f3f3f;
const ll LINF = 1ll * INF * INF;

const int MAX_N = 18;
const int MAX_NN = (1<<MAX_N) + 100;

int N, Nr[MAX_NN];
vector<int> Dp[MAX_N+1][MAX_NN];
int main() {
	cin >> N;
	int NN = (1<<N);
	for(int i=0; i<NN; i++) {
		scanf("%d", &Nr[i]);
		Dp[0][i].push_back(Nr[i]);
	}
	for(int k=0; k<N; k++) {
		for(int i=0; i<NN; i++) Dp[k+1][i] = Dp[k][i];
		for(int i=0; i<NN; i++) {
			if (i & (1<<k)) {
				for(int x: Dp[k][i-(1<<k)]) Dp[k+1][i].push_back(x);
				sort(ALL(Dp[k+1][i]));
				reverse(ALL(Dp[k+1][i]));
				if(SZ(Dp[k+1][i]) > 2) {
					Dp[k+1][i].erase(Dp[k+1][i].begin()+2, Dp[k+1][i].end());
				}
			}
		}
	}

	int ans = 0;
	for(int i=1; i<NN; i++) {
		ans = max(ans, Dp[N][i][0] + Dp[N][i][1]);
		printf("%d\n", ans);
	}
	return 0;
}
