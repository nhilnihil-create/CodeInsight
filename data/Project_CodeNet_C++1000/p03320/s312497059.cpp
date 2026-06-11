#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define E "\n"

using namespace std;
const long long MOD = (long long)1e9 + 7;

int k;
vector<long long> ans, vec;

bool fun(long long a, long long b)
{
	long long da = 0, db = 0;
	long long tmp = a;
	while (tmp) {
		da += tmp % 10;
		tmp = tmp / 10;
	}
	tmp = b;
	while (tmp) {
		db += tmp % 10;
		tmp = tmp / 10;
	}
	if (a/da > b/db) return false;
	else if (a/da < b/db) return true;
	else {
		long long ta = a % da;
		long long tb = b % db;
		if (ta * db <= tb * da) return true;
		else return false;
	}
}

long long gun(long long x)
{
	vec.clear();
	long long cur = 1;
	while (1) {
		if (x/cur == 0) break;
		long long tmp = (x / cur)*cur + cur - 1;
		vec.pb(tmp);
		cur = cur * 10;
	}
	long long mi = vec[0];
	for (int i = 1; i < (int)vec.size(); i++) {
		if (fun(vec[i], mi)) {
			mi = vec[i];
		}
	}
	return mi;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> k;
	long long tmp = 1;
	while (1) {
		ans.pb(tmp);
		if (ans.size() == k) break;
		tmp = gun(tmp + 1);
	}
	for (int i = 0; i < k; i++)
		cout << ans[i] << E;
	//system("pause");
	return 0;
}