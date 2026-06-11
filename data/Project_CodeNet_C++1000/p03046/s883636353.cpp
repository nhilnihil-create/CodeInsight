#include <bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
typedef pair<int,int> pi;
#define FAST ios_base::sync_with_stdio(0);
const int maxn = 100010;

int n,k;
deque <int> dq;

void fail() {
	cout << "-1";
	exit(0);
}

int32_t main() {
	cin >> n >> k;
	if (k > (1<<n)-1) fail();
	
	if (n == 1) {
		if (k == 0) cout << "0 0 1 1";
		else fail();
		return 0;
	}
	
	dq.push_back(k);
	for (int i =0;i<=(1<<n)-1;i++) {
		if (i == k) continue;
		dq.push_front(i);
		dq.push_back(i);
	}
	dq.push_back(k);
	for (auto i: dq) {
		cout << i << " ";
	}
}



