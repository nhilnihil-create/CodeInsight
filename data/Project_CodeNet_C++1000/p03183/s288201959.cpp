#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <climits>
#include <cmath>
#include <utility>
#include <iomanip>

using namespace std;

const int maxn = 1002;
const int maxs = 10002;

int n;
long long f[maxs<<1];

struct block
{
	int w, s, v;
};

bool mycmp(const block &a, const block &b) {
	return a.w + a.s < b.w + b.s;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	vector<block> data(n);

	for (int i = 0; i < n; ++i)
		cin >> data[i].w >> data[i].s >> data[i].v;

	sort(data.begin(), data.end(), mycmp);

	// for (int i = 0; i < n; ++i)
	// 	printf("%d %d %d\n", data[i].w, data[i].s, data[i].v);

	for (int i = 0; i < n; ++i)
		for (int j = min(data[i].s, 20000 - data[i].w); j >= 0; --j)
			f[j+data[i].w] = max(f[j+data[i].w], f[j] + data[i].v);

	long long ans = 0;
	for (int j = 1; j <= 20000; ++j)
		ans = max(ans, f[j]);

	cout << ans << endl;

	return 0;
}