#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

const int maxn = 1e5 + 28;

vector <pair<int, int>> v;
bool mark[maxn];
long long ans, sum;
stack <int> v2;
int type;

int main() {
	int n, k; cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back({ y, x });
	}
	sort(v.rbegin(), v.rend());
	for (int i = 0; i < k; i++) {
		sum += v[i].first;
		if (!mark[v[i].second]) {
			type++;
			mark[v[i].second] = 1;
		}
		else v2.emplace(v[i].first);
	}
	ans = sum + ((long long)type * type);
	for (int i = k; i < n; i++) {
		sum += v[i].first;
		if (!mark[v[i].second]) {
			type++;
			mark[v[i].second] = 1;
		}
		else v2.emplace(v[i].first);
		if (v2.empty()) break;
		sum -= v2.top();
		v2.pop();
		ans = max(ans, (sum + ((long long)type * type)));
	}
	cout << ans << endl;

	return 0;
}