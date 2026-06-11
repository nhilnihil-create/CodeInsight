// Ala be zekrellah tatmaenolgholoob ...
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
#define F first
#define S second
#define MP make_pair
const int maxn = 1e6+9;
const ll mod = 1e9+7;

vector <int> ans;

int main () {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	if (n == 3) {
		cout << "2 5 63\n";
		return 0;
	}
	ans.push_back(2);
	ans.push_back(3);
	ans.push_back(9);
	n -= 3;
	if (n >= 1) {
		ans.push_back(4);
		n -= 1;
	}
	int cur = 15;
	while (n >= 2 && cur <= 30000) {
		ans.push_back(cur);
		cur += 6;
		ans.push_back(cur);
		cur += 6;
		n -= 2;
	}
	cur = 8;
	while (n >= 2 && cur <= 30000) {
		ans.push_back(cur);
		cur += 2;
		ans.push_back(cur);
		cur += 4;
		n -= 2;
	}
	cur = 6;
	while (n) {
		ans.push_back(cur);
		cur += 6;
		n -= 1;
	}
	// ans
	for (auto x : ans)
		cout << x << " ";
	cout << "\n";
}