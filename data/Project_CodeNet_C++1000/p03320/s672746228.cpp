#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<string>
#include<cmath>
#include<cstring>
#include<queue>
#include<map>
#include<climits>
#include<set>

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)
using namespace std;
typedef pair<int, int> pii;
typedef long long int ll;
typedef pair<ll, ll> pll;
int dx[4] = { 1,0,0,-1 };
int dy[4] = { 0,1,-1,0 };
#define MOD 1000000007
#define ARRAY_MAX 100015

//const int INF = 1e9 + 7;


ll s(ll num) {

	ll res = 0;
	while (num > 0) {
		res += num % 10;
		num /= 10;
	}
	return res;
}

bool check(ll n, ll m) {

	if (n*s(m) > m*s(n)) {
		return true;
	}
	else {
		return false;
	}

}


int main() {

	ll k;
	cin >> k;

	vector<ll> res;
	ll base = 1;

	for (int i = 0; i < 15; i++) {
		for (int j = 1; j < 130; j++)
		{
			res.push_back(base*(j + 1) - 1);
		}
		base *= 10;
	}
	sort(res.begin(), res.end());
	res.erase(unique(res.begin(), res.end()), res.end());

	ll siz = res.size();

	for (ll i = 0; i < res.size();++i)
	{
		for (ll j = i+1; j < res.size(); ++j)
		{
			if (check(res[i], res[j])) {
				res.erase(res.begin() + i);
				i--;
				break;
			}
		}
	}

	for (ll i = 0; i < k; i++) {
		cout << res[i] << endl;
	}

	return 0;
}
