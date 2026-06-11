#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <functional>
#include <iomanip>
#include <bitset>
#include <cassert>
using namespace std;
typedef long long ll;

vector<int> edg[5];
bool vis[5];

bool func(int pos) {
	bool ret = true;
	for (int i = 0; i < 4; i++) {
		ret &= pos == i || vis[i];
	}
	if (ret) return true;
	vis[pos] = true;
	for (int to : edg[pos]) {
		if (vis[to]) continue;
		if (func(to)) {
			vis[pos] = false;
			return true;
		}
	}
	vis[pos] = false;
	return false;
}

int main() {
	for (int i = 0; i < 3; i++) {
		int a, b; cin >> a >> b;
		a--; b--;
		edg[a].push_back(b);
		edg[b].push_back(a);
	}
	for (int i = 0; i < 4; i++) {
		if (func(i)) {
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
}