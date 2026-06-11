#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define E "\n"

using namespace std;
const long long MOD = (long long)1e9 + 7;

int n, X, Y, x, y, cur, dat[2000][2];
vector<string> ans;
vector<char> apd;

bool ck(int u, int v, int d)
{
	if (abs(u) + abs(v) <= d) return true;
	return false;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	bool flag0 = false;
	bool flag1 = false;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> dat[i][0] >> dat[i][1];
		if ((abs(dat[i][0]) + abs(dat[i][1]))%2) flag1 = true;
		else flag0 = true;
		if (flag0 && flag1) {
			cout << "-1" << E;
			return 0;
		}
	}
	if (flag1) {
		for (int i = 0; i < n; i++) {
			if (dat[i][0] == 0) {
				if (dat[i][1] > 0) {
					apd.pb('U');
					dat[i][1]--;
				}
				else {
					apd.pb('D');
					dat[i][1]++;
				}
			}
			else if (dat[i][0] > 0) {
				apd.pb('R');
				dat[i][0]--;
			}
			else {
				apd.pb('L');
				dat[i][0]++;
			}
		}
	}
	string s(32, '0');
	int cnt = 0;
	while (cnt < n) {
		X = dat[cnt][0]; Y = dat[cnt][1];
		cnt++;
		x = abs(X); y = abs(Y);
		cur = 30;
		int tmp = (1 << cur);
		while (1) {
			if (ck(x - tmp, y, tmp)) {
				s[cur + 1] = 'R';
				x -= tmp;
			}
			else if (ck(x, y - tmp, tmp)) {
				s[cur + 1] = 'U';
				y -= tmp;
			}
			else if (ck(x + tmp, y, tmp)) {
				s[cur + 1] = 'L';
				x += tmp;
			}
			else {
				s[cur + 1] = 'D';
				y += tmp;
			}
			if (cur == 0) break;
			cur--;
			tmp = tmp / 2;
		}
		if (x == 0) {
			if (y > 0) s[0] = 'U';
			else s[0] = 'D';
		}
		else {
			if (x > 0) s[0] = 'R';
			else s[0] = 'L';
		}
		for (int i = 0; i < 33; i++) {
			if (s[i] == 'L' || s[i] == 'R') {
				if (X < 0) {
					if (s[i] == 'L') s[i] = 'R';
					else s[i] = 'L';
				}
			}
			else {
				if (Y < 0) {
					if (s[i] == 'U') s[i] = 'D';
					else s[i] = 'U';
				}
			}
		}
		ans.pb(s);
	}
	int m = 32;
	if (flag1) m++;
	cout << m << E;
	cout << "1 " << E;
	for (int i = 0; i < 31; i++) cout << (1 << i) << " ";
	if (flag1) cout << 1;
	cout << E;
	for (int i = 0; i < n; i++) {
		cout << ans[i];
		if (flag1) cout << apd[i];
		cout << E;
	}
	//std::system("pause");
	return 0;
}