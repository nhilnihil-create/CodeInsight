#pragma region template
#include "bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD = 1e9+7, MAX = 1e18, larg = 1e5, INF = -1e18;
long long A, B, C, D, E, F, G, H, I, J, K, L, N, M, O, P, Q, R, S, T, U, V, W, x, y, z;
long long max_value = INF, max_index = -1;
long long min_value = MAX, min_index = -1;
typedef long long ll;
typedef pair<ll, ll> Pa;

ll arr[2000];
vector<ll> ans;
int main() {
	cin >> N >> A >> B;
	rep(i, N) {
		cin >> arr[i];
	}
	if (N < 2) cout << abs(B - arr[0]);
	else cout << max(abs(B - arr[N - 1]), abs(arr[N - 1] - arr[N - 2]));
}
