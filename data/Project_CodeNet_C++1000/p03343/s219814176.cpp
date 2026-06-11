#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
using namespace std;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, K, Q;
	cin >> N >> K >> Q;
	vector<int> A(N);
	for (auto & e : A) cin >> e;
	A.push_back(0);//番兵
	vector<int> removable;
	vector<int> tmp;
	int ans = 1000*1000*1000 + 1;

	for (const auto& x : A) {
		if (x == 0) continue;//breakでも同じだが。
		for (const auto & e : A) {
			if (e >= x) {
				tmp.push_back(e);
				continue;
			}
			if (tmp.size() >= K) {
				sort(tmp.begin(), tmp.end());
				for (int i = 0; i < tmp.size() - K + 1; ++i) {
					removable.push_back(tmp[i]);
				}
			}
			tmp.clear();
		}
		if (removable.size() >= Q) {
			sort(removable.begin(), removable.end());
			ans = min(ans, removable[Q - 1] - removable[0]);
		}
		removable.clear();
	}
	cout << ans << endl;
}