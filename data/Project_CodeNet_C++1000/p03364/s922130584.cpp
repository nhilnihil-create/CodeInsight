// In The Namw Of Allah
#include <bits/stdc++.h>
using namespace std;

const int N = 3e3 + 10;
typedef pair <int, int> pii;
typedef long long ll;

string s[N];
int cnt[2][N], col[N][30], row[N][30];
char t[N][N];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> s[i];
	int ans = 0;
	for (int k = 0; k < n; k++) {
		bool ok = true;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int ii = i, jj = (j + k) % n;
				t[ii][jj] = s[i][j];
			}
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if(t[i][j] != t[j][i])	ok = 0;
		ans += ok;
	}
	cout << ans * n << "\n";
}