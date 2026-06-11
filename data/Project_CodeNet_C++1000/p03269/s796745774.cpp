#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define E "\n"

using namespace std;
const long long MOD = (long long)1e9 + 7;

struct node {
	int u;
	int v;
	int len;
};

int L;
string s;
vector<node> ans;
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> L;
	s = "";
	int cur = 1;
	while (1) {
		if (L&cur) s = "1" + s;
		else s = "0" + s;
		cur = cur << 1;
		if (cur > L) break;
	}
	int cnt = s.length();
	for (int i = 1; i < cnt; i++) {
		int tmp = cnt - 1 - i;
		int v = 1 << tmp;
		ans.pb({ i - 1, i, v });
		ans.pb({ i - 1, i, 0 });
	}
	int pre = 0;
	int acc = 0;
	for (int i = 1; i < cnt; i++) {
		if (s[i] == '0') continue;
		int tmp = cnt - 1 - pre;
		int v = 1 << tmp;
		acc += v;
		ans.pb({ 0, i, acc });
		pre = i;
	}
	cout << cnt << " " << (int)ans.size() << E;
	for (int i = 0; i < (int)ans.size(); i++) {
		cout << ans[i].u + 1 << " " << ans[i].v + 1 << " " << ans[i].len << E;
	}
	//system("pause");
	return 0;
}