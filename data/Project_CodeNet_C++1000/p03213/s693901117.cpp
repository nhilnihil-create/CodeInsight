#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int inf = 1001001001;
const int mod = 1000000007;

class Prime
{
	ll i, iLimit;
public:
	bool isPrime(ll a);
};

bool Prime::isPrime(ll a)
{
	if (a == 1) return false;
	iLimit = (int)sqrt(a);
	for (i = 2; i <= iLimit; i++) if (a % i == 0) break;
	return (i == iLimit + 1 ? true : false);
}

vector<int> mp;
int n;
int ans = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	Prime p;
	for (int i = 2; i <= n; ++i) {
		bool elf = p.isPrime(i);
		if (!elf) continue;
		int res = 0;
		for (int j = i; j <= n; ++j) {
			int tmp = j;
			while (tmp % i == 0) {
				tmp /= i;
				res++;
			}
		}
		mp.emplace_back(res);
	}
	int ans = 0;
	for (auto& c : mp) {
		if (c >= 74) ans++;
	}
	int m = mp.size();
	rep(i, m - 1) {
		for (int j = i + 1; j < m; ++j) {
			if (mp[i] >= 4 && mp[j] >= 14) ans++;
			if (mp[j] >= 4 && mp[i] >= 14) ans++;
			if (mp[i] >= 2 && mp[j] >= 24) ans++;
			if (mp[i] >= 24 && mp[j] >= 2) ans++;
		}
	}
	rep(i, m - 2) {
		for (int j = i + 1; j < m - 1; ++j) {
			for (int k = j + 1; k < m; ++k) {
				if (mp[i] >= 4 && mp[j] >= 4 && mp[k] >= 2) ans++;
				if (mp[i] >= 4 && mp[j] >= 2 && mp[k] >= 4) ans++;
				if (mp[i] >= 2 && mp[j] >= 4 && mp[k] >= 4) ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
