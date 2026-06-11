#include <iostream>
#include <vector>
#include <string>
using namespace std;

long long power[22], N, x[1009], y[1009], G[2]; vector<long long>E;

string solve(long long X, long long Y) {
	int cnt = 0; string ans = ""; long long rx = 0, ry = 0;
	for (int i = 0; i < E.size(); i += 2) {
		cnt++;
		vector<long long>H; H.push_back(E[i]); if (i != E.size() - 1) H.push_back(E[i + 1]);

		for (int j = 0; j < (1 << (2 * H.size())); j++) {
			long long vx = rx, vy = ry; int dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 }; char c[5] = "RULD";
			string rem = "";

			for (int k = 0; k < H.size(); k++) {
				vx += H[k] * dx[(j / (1 << (2 * k))) % 4];
				vy += H[k] * dy[(j / (1 << (2 * k))) % 4];
				rem += c[(j / (1 << (2 * k))) % 4];
			}
			
			if ((X - vx + power[20]) % power[cnt] == 0 && (Y - vy + power[20]) % power[cnt] == 0 && (i < E.size() - 2 || (vx == X && vy == Y))) {
				rx = vx; ry = vy; ans += rem;
				break;
			}
		}
	}
	return ans;
}

int main() {
	power[0] = 1; for (int i = 1; i <= 22; i++) power[i] = power[i - 1] * 3;

	cin >> N;
	for (int i = 1; i <= N; i++) { cin >> x[i] >> y[i]; G[(x[i] + y[i] + 10000000000LL) % 2]++; }

	if (G[0] >= 1 && G[1] >= 1) { cout << "-1" << endl; return 0; }
	for (int i = 0; i < 20; i++) { E.push_back(power[i]); E.push_back(power[i]); }
	if (G[1] >= 1) E.pop_back();

	cout << E.size() << endl;
	for (int i = 0; i < E.size(); i++) { if (i) cout << " "; cout << E[i]; } cout << endl;
	for (int i = 1; i <= N; i++) {
		cout << solve(x[i], y[i]) << endl;
	}
	return 0;
}