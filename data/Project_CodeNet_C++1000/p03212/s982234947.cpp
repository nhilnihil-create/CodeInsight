#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define MOD 1000000000 + 7
#define PI 3.14159265359

const long long INF = 100000;
typedef pair<int,int> P;
typedef long long ll;

using Graph = vector<vector<int>>;

vector<ll> v;// 753数を格納する配列

// 引数kの末尾に3 or 5 or 7を付けてvに加えるdfs 付け加える数がN以下の時だけ
void dfs(ll k, ll N) {
	if (k > N) return;

	if (k*10 + 3 > N) return;
	v.push_back(k*10 + 3);
	dfs(10*k + 3, N);

	if (k*10 + 5 > N) return;
	v.push_back(k*10 + 5);
	dfs(10*k + 5, N);

	if (k*10 + 7 > N) return;
	v.push_back(k*10 + 7);
	dfs(10*k + 7, N);
}

// Nが753数かどうかチェックする関数
bool check(ll N) {
	bool flag3 = false;
	bool flag5 = false;
	bool flag7 = false;

	while (N) {
		int c = N % 10;// Nの末尾の桁　末尾から見ていく
		N /= 10;
		if (c == 3) flag3 = true;
		if (c == 5) flag5 = true;
		if (c == 7) flag7 = true; 

	}
	if (flag3 && flag5 && flag7) return true;
	else return false;
}

int main() {
    ll N;
	cin >> N;
	dfs(3, N);
	dfs(5, N);
	dfs(7, N);

	/*for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}*/
	int ans = 0;
	for (ll i = 0; i < v.size(); i++) {
		if (check(v[i])) ans++;
	}
	cout << ans << endl;
}
