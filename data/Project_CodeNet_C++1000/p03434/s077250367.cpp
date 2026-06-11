#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;
const ll INF = 1LL<<60;
//int INF = numeric_limits<int>::max();

int main(int, char**) {
	int n; cin >> n;
	priority_queue<int> que;
	for (int i=0; i<n; i++) {
		int a; cin >> a;
		que.push(a);
	}
	int a = 0;
	int b = 0;
	for (int i=0; i<n; i++) {
		int now = que.top();
		que.pop();
		if (i%2==0) a += now;
		else b += now;
	}
	cout << a - b << endl;
	return 0;
}
