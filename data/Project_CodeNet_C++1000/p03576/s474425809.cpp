#pragma region template
#include "bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD = 1e9 + 7, MAX = LLONG_MAX, larg = 1e5, INF = -1e9;
long long A, B, C, D, E, F, G, H, I, J, K, L, N, M, O, P, Q, R, S, T, U, V, W;
typedef long long ll;
typedef pair<ll, ll> Pa;

Pa arr[50];
ll xarray[50];
ll yarray[50];
int main() {
	cin >> N >> K;
	rep(i, N) {
		cin >> A >> B;
		arr[i] = Pa(A, B);
		xarray[i] = A;
		yarray[i] = B;
	}
	sort(xarray, xarray + N);
	sort(yarray, yarray + N);

	ll ans = MAX;
	for (int x1 = 0; x1 < N - 1; x1++) {
		for (int x2 = x1 + 1; x2 < N; x2++) {
			for (int y1 = 0; y1 < N - 1; y1++) {
				for (int y2 = y1 + 1; y2 < N; y2++) {
					int cnt = 0;
					rep(i, N) {
						if (xarray[x1] <= arr[i].first && arr[i].first <= xarray[x2] &&
							yarray[y1] <= arr[i].second && arr[i].second <= yarray[y2])cnt++;
						if (cnt == K) break;
					}
					if (cnt == K) {
						ans = min(ans, (xarray[x2] - xarray[x1]) * (yarray[y2] - yarray[y1]));
					}
				}
			}
		}
	}
	cout << ans;
}
