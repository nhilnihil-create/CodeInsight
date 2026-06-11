#include "bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD = 1e9 + 7, MAX = 1e18, larg = 1e5, INF = -1e9;
long long A, B, C, D, E, F, G, H, I, J, K, L, N, M, O, P, Q, R, S, T, U, V, W;
typedef long long ll;
typedef pair<ll, ll> Pa;

map<int, Pa> mp;
int sum[90001];
int main()
{
	cin >> H >> W >> D;
	rep(i, H) {
		rep(j, W) {
			cin >> A; A--;
			mp[A] = Pa(i, j);
		}
	}
	rep(i, D) {
		sum[i] = 0;
	}
	for (int i = D; i < H * W; i++) {
		sum[i] += sum[i - D] + abs(mp[i].first - mp[i - D].first) + abs(mp[i].second - mp[i - D].second);
	}
	vector<int> ans;
	cin >> Q;
	rep(i, Q) {
		cin >> A >> B; A--; B--;
		ans.push_back(sum[B] - sum[A]);
	}
	rep(i, Q) {
		cout << ans[i] << endl;
	}
}
