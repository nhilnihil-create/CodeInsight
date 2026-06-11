#include "bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD = 1e9 + 7, MAX = 1e18, larg = 1e5, INF = -1e9;
long long A, B, C, D, E, F, G, H, I, J, K, L, N, M, O, P, Q, R, S, T, U, V, W;
typedef long long ll;
typedef pair<ll, ll> Pa;
typedef pair<Pa, ll> info;

vector<info> infos;
int main()
{
	cin >> N;
	rep(i, N - 1) {
		cin >> A >> B >> C;
		infos.push_back(info(Pa(B, C), A));
	}
	rep(i, N) {
		int curr_pos = i;
		int curr_time = 0;
		while (curr_pos != N - 1) {
			Pa p = infos[curr_pos].first;
			if (curr_time > p.first) {
				curr_time = ((curr_time - 1) / p.second + 1) * p.second;
			}
			else {
				curr_time = p.first;
			}
			curr_time += infos[curr_pos].second;
			curr_pos++;
		}
		cout << curr_time << endl;
	}
}
