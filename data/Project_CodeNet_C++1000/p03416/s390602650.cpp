#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;

int main() {
	int a, b;
	cin >> a >> b;
	int l, r,cnt=0;
	for (int i = a; i <= b; i++) {
		l = i / 1000;
		r = i % 100;
		if (l/10 == r%10 && l%10 == r/10)cnt++;
	}
	cout << cnt << endl;
	return 0;
}

