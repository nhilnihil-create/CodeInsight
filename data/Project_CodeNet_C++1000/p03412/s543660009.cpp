#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define endl "\n"
#define ll long long
#define oo 0x3f3f3f3fLL
#define sz(s) (int)(s.size())
#define RT(s) return cout<<s,0
#define INF 0x3f3f3f3f3f3f3f3fLL
#define all(v) v.begin(),v.end()
#define watch(x) cout<<(#x)<<" = "<<x<<endl
const int dr[] { -1, -1, 0, 1, 1, 1, 0, -1 };
const int dc[] { 0, 1, 1, 1, 0, -1, -1, -1 };
#if __cplusplus >= 201402L
template<typename T>
vector<T> create(size_t n) {
	return vector<T>(n);
}
template<typename T, typename ... Args>
auto create(size_t n, Args ... args) {
	return vector<decltype(create<T>(args...))>(n, create<T>(args...));
}
#endif
void run() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
#else
#endif
}

int count(vector<int> a, vector<int> b, int bit) {
	int mn = (1 << bit), mx = (1 << bit + 1) - 1, cnt = 0;
	for (auto &it : a)
		it &= mx;
	for (auto &it : b)
		it &= mx;
	sort(all(b));
	for (int i = 0; i < sz(a); i++) {
		cnt += upper_bound(all(b), mx - a[i]) - lower_bound(all(b), mn - a[i]);
		cnt += upper_bound(all(b), mx + 1 + mx - a[i])
				- lower_bound(all(b), mx + 1 + mn - a[i]);
		cnt &= 1;
	}

	return cnt;
}

int main() {
	//run();
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (auto &it : a)
		cin >> it;
	for (auto &it : b)
		cin >> it;
	int res = 0;
	for (int bit = 0; bit < 30; bit++)
		if (count(a, b, bit))
			res |= (1 << bit);
	cout << res << endl;
}
