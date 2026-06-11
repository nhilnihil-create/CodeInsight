#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 10;
vector<pair<int, int> > edg;
pair<ll, int> d[MAXN];
vector<int> Mat[MAXN];
int n, cnt[MAXN];
map<ll, int> mp;
bool se[MAXN];
ll dist, dt;
int num;

void dfs(int v, int di) {
	se[v] = 1, num++;
	dist += di;
	for (int i = 0; i < Mat[v].size(); i++)
		if (!se[Mat[v][i]])
			dfs(Mat[v][i], di + 1);
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> d[i - 1].first;
		if (i == 1)
			dt = d[i - 1].first;
		mp[d[i - 1].first] = i;
		d[i - 1].second = i;
		cnt[i] = 1;
	}
	sort(d, d + n);
	reverse(d, d + n);
	for (int i = 0; i < n - 1; i++) {
		int k = cnt[d[i].second];
		if (2 * k > n || mp.find(d[i].first + k - (n - k)) == mp.end())
			return cout << -1, 0;
		cnt[mp[d[i].first + k - (n - k)]] += k;
		edg.push_back({d[i].second, mp[d[i].first + k - (n - k)]});
		Mat[mp[d[i].first + k - (n - k)]].push_back(d[i].second);
		Mat[d[i].second].push_back(mp[d[i].first + k - (n - k)]);
	}
	dfs(1, 0);
	if (dist == dt && num == n && edg.size() == n - 1) {
		for (int i = 0; i < edg.size(); i++)
			cout << edg[i].first << ' ' << edg[i].second << endl;
		return 0;
	}
	cout << -1;
}