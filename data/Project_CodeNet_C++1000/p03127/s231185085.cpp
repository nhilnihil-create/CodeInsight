#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	int n;
	cin >> n;
	//vector<long long> a(n);
	priority_queue<long long, vector<long long>, greater<long long>> q;
	for (int i = 0; i < n; i++) {
		//cin >> a[i];
		long long a;
		cin >> a;
		q.push(a);
	}

	while (q.size() >= 2) {
		long long tmp0 = q.top();
		q.pop();
		long long tmp1 = q.top();
		q.pop();
		long long r = tmp1 % tmp0;
		tmp1 = r;
		if (r != 0)
			q.push(r);
		q.push(tmp0);
	}
	cout << q.top() << endl;
	return 0;
}