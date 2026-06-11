#pragma region template
#include "bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD = 1e9 + 7, MAX = 1e18, larg = 1e5, INF = -1e9;
long long A, B, C, D, E, F, G, H, I, J, K, L, N, M, O, P, Q, R, S, T, U, V, W;
typedef long long ll;
typedef pair<ll, ll> Pa;
typedef pair<ll, Pa> program;

vector<program> info;
vector<program> programs;

int time_sum[100001];
int main() {
	cin >> N >> C;
	rep(i, N) {
		cin >> A >> B >> D; A--; B--;
		info.push_back(program(D, Pa(A, B)));
	}
	sort(info.begin(), info.end());
	int left = info[0].second.first;
	int prev = info[0].second.second;
	int ch = info[0].first;
	rep(i, N - 1) {
		if (ch == info[i + 1].first && prev == info[i + 1].second.first) {
			prev = info[i + 1].second.second;
		}
		else {
			programs.push_back(program(ch, Pa(left, prev)));
			left = info[i + 1].second.first;
			prev = info[i + 1].second.second;
			ch = info[i + 1].first;
		}
	}
	programs.push_back(program(ch, Pa(left, prev)));
	memset(time_sum, 0, 100001);
	rep(i, programs.size()) {
		time_sum[programs[i].second.first]++;
		time_sum[programs[i].second.second + 1]--;
	}
	int maxv = 0;
	rep(i, 100000) {
		time_sum[i + 1] += time_sum[i];
		maxv = max(maxv, time_sum[i + 1]);
	}
	cout << maxv;
}
