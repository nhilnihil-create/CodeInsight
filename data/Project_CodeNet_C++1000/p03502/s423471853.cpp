#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;	

int main() {
	int n, sum, i; cin >> n;
	sum = 0;
	i = n;

	while (i > 0) {
		sum += i % 10;
		i /= 10;
	}
	if (n % sum == 0) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
;}
