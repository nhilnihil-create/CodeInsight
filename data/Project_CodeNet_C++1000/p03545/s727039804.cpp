#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 25;
const int MOD = 1e9+7;
int num[3];
int main() {
	int a, n;
	cin>>n;
	a = n / 1000;
	n %= 1000;
	num[0] = n / 100;
	n %= 100;
	num[1] = n / 10;
	n %= 10;
	num[2] = n;
	
	rep(s,1<<3) {
		int now = a;
		rep(i,3) {
			if ((s>>i) & 1) {
				now += num[i];
			} else now -= num[i];
		} 
		if (now == 7) {
			cout << a;
			rep(i,3) {
				if ((s>>i) & 1) cout << '+';
				else cout << '-';
				cout << num[i];
			}
			cout << "=7" << endl;
			return 0;
		}
	}
	return 0;
}