#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>

using namespace std;
typedef long long ll;
typedef double db;
#define inf 0x3f3f3f3f
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int a[110];
int n, i, j, k;
stack<int>sta;
signed main() {
	cin >> n;
	for (i = 1; i <= n; ++i)cin >> a[i];
	for (i = 1; i <= n; ++i) {
		if (a[i] > i) {
			cout << -1 << endl;
			return 0;
		}
	}
	for (i = n; i > 0; --i) {
		int temp = 1;
		for (j = i; j > 0; --j) {
			if (a[j] == j)break;
		}
		sta.push(j);
		for (; j < i; ++j)a[j] = a[j + 1];
	}
	while (!sta.empty()) {
		cout << sta.top() << endl;
		sta.pop();
	}
	return 0;
}