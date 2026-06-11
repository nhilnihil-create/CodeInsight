#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;	

int main() {
	int a, b, t;
	cin >> a >> b >> t;
	int count = 0;

	for (int i = 1; i * a <= t; i++) {
		count += b;
	}
	cout << count << endl;
}
