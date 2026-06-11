#include<bits/stdc++.h>
#define int long long
#define for0(i, n) for(int i = 0; i < (n); i++)
#define for1(i, n) for(int i = 1; i <= (n);i++)
#define all(x) x.begin(),x.end()
#define puts(x) cout << x << "\n"
using namespace std;
int x, y, z, k, a[1234], b[1234], c[1234];
priority_queue<int, vector<int>, greater<int>> pq;
vector<int>v, ans;
signed main() {
	cin >> x >> y >> z >> k;
	for1(i, x)cin >> a[i];
	for1(j, y)cin >> b[j];
	for1(l, z)cin >> c[l];
	for1(j, y)for1(l, z) {
		pq.push(b[j] + c[l]);
		if (pq.size() > k)pq.pop();
	}
	while (pq.size()) {
		v.push_back(pq.top());
		pq.pop();
	}
	for (int vp : v)for1(i, x) {
		pq.push(vp + a[i]);
		if (pq.size() > k)pq.pop();
	}
	while (pq.size()) {
		ans.push_back(pq.top());
		pq.pop();
	}
	sort(all(ans), greater<int>());
	for0(i, k)puts(ans[i]);
}