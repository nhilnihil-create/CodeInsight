#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <queue>
#include <time.h>
using namespace std;
typedef long long ll;


int main()
{
	int N, M; cin >> N >> M;
	vector<pair<int, int>> I(M);
	for (int i = 0; i < M; ++i) {
		cin >> I[i].first >> I[i].second;
	}
	auto cmpr = [](pair<int, int> a, pair<int, int> b) {
		if (a.second != b.second) return a.second < b.second;
		return a.first > b.first;
	};
	sort(I.begin(), I.end(), cmpr);
	int cur = 1 << 30; cur *= -1;
	int ans = 0;
	for (int i = 0; i < M; ++i) {
		if (cur > I[i].first) continue;
		cur = I[i].second;
		++ans;
	}
	cout << ans << endl;
}
