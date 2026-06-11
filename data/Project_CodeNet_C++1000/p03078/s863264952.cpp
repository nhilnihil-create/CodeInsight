#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <deque>
#include <cstdio>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <cctype>
using namespace std;
long long a[1010], b[1010], c[1010];
int main() {
	int x, y, z, k;
	cin >> x >> y >> z >> k;
	for (int i = 0; i < x; i++) {
		cin >> a[i];
	}
	sort(a, a + x);
	for (int i = 0; i < y; i++) {
		cin >> b[i];
	}
	sort(b, b + y);
	for (int i = 0; i < z; i++) {
		cin >> c[i];
	}
	sort(c, c + z);
	int co = 0;
	set<tuple<long long, int, int, int>> st;
	priority_queue<tuple<long long, int, int, int>> que;
	que.push(make_tuple(a[x - 1] + b[y - 1] + c[z - 1], x - 1, y - 1, z - 1));
	while (co < k) {
		int bo = st.size();
		tuple<long long, int, int, int> t = que.top();
		st.insert(t);
		if (bo != st.size()) {
			long long d = get<0>(t);
			int e = get<1>(t);
			int f = get<2>(t);
			int g = get<3>(t);
			cout << d << endl;
			co++;
			if (e != 0) {
				que.push(make_tuple(d - a[e] + a[e - 1], e - 1, f, g));
			}
			if (f != 0) {
				que.push(make_tuple(d - b[f] + b[f - 1], e, f - 1, g));
			}
			if (g != 0) {
				que.push(make_tuple(d - c[g] + c[g - 1], e, f, g - 1));
			}
		}
			que.pop();
	}
	return 0;
}
