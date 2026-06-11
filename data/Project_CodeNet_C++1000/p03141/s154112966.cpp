#include<bits/stdc++.h>
using namespace std;

#define X first
#define Y second

const int MAXN = 1e5 + 5;
long long ans;
long long a[MAXN], b[MAXN];
vector<long long> s;
int n;

void input();
void solve();

int main() {
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	input();
	solve();
	return 0;
}

void input() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i] >> b[i], s.push_back(-a[i] - b[i]), ans -= b[i];
}

void solve() {
	sort(s.begin(), s.end());
	for (int i = 0; i < n; i += 2)
		ans -= s[i];
	cout << ans;
}
