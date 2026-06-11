#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair <ll,ll> P;
#define REP(i, n) for(ll i = 0LL; i < (ll)(n); i++)
#define REPR(i, n) for(ll i = n-1; i >= 0LL; i--)
#define FOR(i, n, m) for(ll i = n; i < (ll)(m); i++)
#define PRINT(x) cout << x << endl
#define ALL(v) v.begin(), v.end()
#define INF (ll)1e18
#define INFD 1e18
#define PI 3.14159265358979
#define MOD 1000000007
#define vl vector<ll>

vector<ll> dx = {-1, 1, 0, 0};
vector<ll> dy = {0, 0, 1, -1};

ll gcd(ll a, ll b) { return b ? gcd(b,a%b) : a;}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int main()
{
	ll N;
	cin >> N;
	vector<vector<ll>> tree(N, vector<ll>());
	REP(i, N-1) {
		ll a, b;
		cin >> a >> b;
		a--; b--;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	vector<ll> c(N);
	REP(i, N) cin >> c[i];
	sort(ALL(c));
	ll M = 0;
	REP(i, N-1) {
		M += c[i];
	}
	reverse(ALL(c));
	vector<bool> visited(N,false);
	queue<ll> que;
	que.push(0);
	visited[0] = true;
	vector<ll> ans(N);
	ll cnt = 1;
	ans[0] = c[0];
	while(!que.empty()) {
		ll t = que.front();
		que.pop();
		REP(i, tree[t].size()) {
			if (!visited[tree[t][i]]) {
				que.push(tree[t][i]);
				visited[tree[t][i]] = true;
				ans[tree[t][i]] = c[cnt];
				cnt++;
			}
		}
	}
	PRINT(M);
	REP(i, N) {
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}
