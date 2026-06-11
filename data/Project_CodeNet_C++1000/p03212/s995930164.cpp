#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long int64;
const double PI = 3.14159265358979323846;
const double EPS = 1e-12;
const int INF = 1<<29;
const long long  INFL = 1e18;
const int MOD = 1000000007;
const int MAX = 210000;
const int MAX_NUM = 999999999;
int64 N;
int ans;
vector<int> target = {7, 5, 3};
void dfs(int64 num) {
	if (num > N) return;
	int64 t_num = num; 
	int flg = 0;
	while (t_num > 0) {
		int modulo = t_num % 10;
		if (modulo == 7) flg |= 1;
		if (modulo == 5) flg |= 2;
		if (modulo == 3) flg |= 4;
		t_num /= 10;	
	}
	if (flg == 7) ans++;
	for (int i = 0; i < target.size(); ++i) {
		dfs((num * 10) + target[i]);
	}
}
void solve() {
	cin >> N;
	for (int i = 0; i < target.size(); ++i) {
		dfs(target[i]);
	}
	cout << ans << endl;
	return;
}
int main() {
	solve();
	return 0;
}