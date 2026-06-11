#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <map>
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

int main() {
	int n=0, m=0;
	cin >> n >> m;
	vector<pair<int,int> > vec;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		vec.push_back({ b, a });
	}
	sort(vec.begin(), vec.end());
	int ans=1, broke;
	broke = vec[0].first-1;
	for (int i = 1; i < m; i++) {
		if (broke < vec[i].first&& broke >= vec[i].second)continue;
		ans++;
		broke = vec[i].first - 1;
	}
	cout << ans << endl;
	return 0;
}