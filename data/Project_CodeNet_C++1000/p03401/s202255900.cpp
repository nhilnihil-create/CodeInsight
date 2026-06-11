#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
#define pb(a) push_back(a)

typedef long long ll;
using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

//const int dy[] = { 0, 0, 1, -1 };
//const int dx[] = { 1, -1, 0, 0 };
const int dx[8] = { 1, 0, -1, 0, 1, -1, -1, 1 };
const int dy[8] = { 0, 1, 0, -1, 1, 1, -1, -1 };
ll gcd(ll a, ll b);
ll lcm(ll x, ll y);

vector<ll> a,ans;

int main()
{
	ll n, x;
	ll s = 0;
	cin >> n;
	ans.push_back(0);
	for (ll i = 0; i < n; i++){
		ll tmp;
		cin >> tmp;
		a.push_back(tmp);
		ans.push_back(tmp);
	}
	ans.push_back(0);

	for (ll i = 0; i < n+1; i++) {
		s += abs(ans[i] - ans[i + 1]);
	}
	
	for (ll i = 1; i < n+1; i++) {
		ll tmp = s + abs(ans[i - 1] - ans[i + 1]) - (abs(ans[i - 1] - ans[i]) + abs(ans[i] - ans[i + 1]));
		cout << tmp << endl;
	}
	
	return 0;
}
