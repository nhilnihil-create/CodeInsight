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
	bool flg_7 = false;
	bool flg_5 = false;
	bool flg_3 = false;
	while (t_num > 0) {
		int modulo = t_num % 10;
		if (modulo == 7) flg_7 = true;
		if (modulo == 5) flg_5 = true;
		if (modulo == 3) flg_3 = true;
		t_num /= 10;	
	}
	if (flg_7 == true && flg_5 == true && flg_3 == true) ans++;
	dfs((num * 10) + target[0]);
	dfs((num * 10) + target[1]);
	dfs((num * 10) + target[2]);	
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