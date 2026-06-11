// Comment
//

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

const int MAX_N = 1e5 + 100;

int N;
ll M, X[MAX_N], C[MAX_N];
ll Sum[2][MAX_N], Max[2][MAX_N];
int main() {
	cin >> N >> M;
	X[0] = 0; X[N+1] = M;
	for(int i=1; i<=N; i++) scanf("%lld%lld", &X[i], &C[i]);
	for(int i=1; i<=N; i++) Sum[0][i] = Sum[0][i-1] + C[i] - (X[i] - X[i-1]);
	for(int i=N; i>=1; i--) Sum[1][i] = Sum[1][i+1] + C[i] - (X[i+1] - X[i]);
	for(int i=1; i<=N; i++) Max[0][i] = max(Sum[0][i], Max[0][i-1]);
	for(int i=N; i>=1; i--) Max[1][i] = max(Sum[1][i], Max[1][i+1]);

	ll ans = max(Max[0][N], Max[1][1]);
	for(int i=0; i<=N-1; i++) ans = max(ans, Sum[0][i] - (    X[i]) + Max[1][i+1]);
	for(int i=N; i>=1  ; i--) ans = max(ans, Sum[1][i] - (M - X[i]) + Max[0][i-1]);
	cout << ans << endl;
	return 0;
}
