#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
int div2 (int a) {
	int cnt = 0;
	while (a % 2 == 0)
	{
		cnt++;
		a /= 2;
	}
	return cnt;
}
 
int main() {
	int n;
	cin >> n;
	ll pi = 1;
	int cnt = 0;
	rep(i, n) {
		int a; cin >> a;
		cnt += div2(a);
	}
	
	cout << cnt << endl;
	return 0;
}