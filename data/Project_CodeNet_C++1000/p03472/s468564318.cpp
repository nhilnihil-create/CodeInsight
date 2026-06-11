#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	int n;
	long long h;
	cin >> n >> h;
	priority_queue<pair<long long, bool>> q;
	for (int i = 0; i < n; i++) {
		long long a, b;
		cin >> a >> b;
		q.push(make_pair(a, false));
		q.push(make_pair(b, true));
	}
	long long count = 0;
	while (h > 0) {
		auto t = q.top();
		if (t.second == true) {
			q.pop();
		}
		h -= t.first;
		count++;
	}
	cout << count << endl;
	return 0;
}