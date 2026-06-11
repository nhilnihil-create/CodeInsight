#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
typedef long long ll;
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
bool check(ll x, ll y, ll s) {
	if (x < 0) x = -x;
	if (y < 0) y = -y;
	return x + y <= s;
}
ll x[MAXN], y[MAXN];
int main() {
	int n; read(n);
	int cnt[2] = {0, 0};
	for (int i = 1; i <= n; i++) {
		read(x[i]), read(y[i]);
		cnt[(x[i] + y[i]) % 2 == 0]++;
	}
	if (cnt[0] != 0 && cnt[1] != 0) {
		puts("-1");
		return 0;
	}
	vector <ll> ans, sum;
	ans.push_back(1);
	if (cnt[1]) ans.push_back(1);
	for (int i = 2; i <= 38; i++)
		ans.push_back(1ll << (i - 1));
	sum.push_back(0);
	for (unsigned i = 1; i < ans.size(); i++)
		sum.push_back(sum.back() + ans[i - 1]);
	cout << ans.size() << endl;
	for (auto x : ans)
		printf("%lld ", x);
	printf("\n");
	for (int i = 1; i <= n; i++) {
		string res; res.resize(ans.size());
		ll nowx = x[i], nowy = y[i];
		for (int j = ans.size() - 1; j >= 0; j--) {
			if (check(nowx + ans[j], nowy, sum[j])) {
				res[j] = 'L';
				nowx += ans[j];
			} else if (check(nowx - ans[j], nowy, sum[j])) {
				res[j] = 'R';
				nowx -= ans[j];
			} else if (check(nowx, nowy + ans[j], sum[j])) {
				res[j] = 'D';
				nowy += ans[j];
			} else if (check(nowx, nowy - ans[j], sum[j])) {
				res[j] = 'U';
				nowy -= ans[j];
			}
		}
		cout << res << endl;
	}
	return 0;
}