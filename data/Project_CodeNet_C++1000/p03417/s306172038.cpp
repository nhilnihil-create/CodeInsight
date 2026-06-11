#pragma region template
#include "bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD = 1e9 + 7, MAX = 1e18, larg = 1e5, INF = -1e9;
long long A, B, C, D, E, F, G, H, I, J, K, L, N, M, O, P, Q, R, S, T, U, V, W, x, y, z;
long long max_value = INF, max_index = -1;
long long min_value = MAX, min_index = -1;
typedef long long ll;
typedef pair<ll, ll> Pa;

int main() {
	cin >> N >> M;
	if(N == 1 && M == 1) cout << 1;
	else if(N == 1 || M == 1) cout << max(N, M) - 2;
	else cout << N*M - (2*N + 2*M - 4);
}

