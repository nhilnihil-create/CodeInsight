#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define MOD 1000000000 + 7
#define PI 3.14159265359

const long long INF = 100000;
typedef pair<int,int> P;
typedef long long ll;

using Graph = vector<vector<int>>;

vector<string> v;

//753数か判定
bool hantei(string S) {
	int N = S.size();
	bool flag3 = false;
	bool flag5 = false;
	bool flag7 = false;

	rep (i, N) {
		if (S[i] == '3') flag3 = true;
		if (S[i] == '5') flag5 = true;
		if (S[i] == '7') flag7 = true;
	}
	
	if (flag3 && flag5 && flag7) return true;
	else return false;
}

ll N;
void dfs(string S) {
	ll k = stoll(S);
	if (k > N) return;
	
	v.push_back(S);

	dfs(S + '3');
	dfs(S + '5');
	dfs(S + '7');

}

int main() {
	cin >> N;
	dfs("3");
	dfs("5");
	dfs("7");

	int ans = 0;
	for (int i = 0; i < v.size(); i++) {
		if (hantei(v[i])) ans++;
	}

	cout << ans << endl;
}