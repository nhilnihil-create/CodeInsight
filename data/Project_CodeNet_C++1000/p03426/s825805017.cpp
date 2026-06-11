#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
#define reps(i,n) for(int i = 1; i <= n; i++)
#define rrep(i,n) for(int i = n-1; i >= 0; i--)
#define rreps(i,n) for(int i = n; i >= 1; i--)
#define mrep(i,from,n) for(int i = from; i < n; i++)
#define mreps(i,from,n) for(int i = from; i <= n; i++)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define ERASE(x,val) x.erase(remove(ALL(x), val), x.end())
typedef long long ll;
typedef pair<int, int> P;
template<class T>inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; }return false; }
template<class T>inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; }return false; }
ll MOD = 1000000007;
int INF = 1001001001;

void solve()
{
	int h,w,d; cin >> h >> w >> d;
	map<int, P> mp;
	rep(i, h)rep(j, w)
	{
		int a;cin >> a;
		mp[a] = {i, j};
	}
	mp[0] = mp[d];
	vector<vector<int>> cost(d, vector<int>(h*w/d+1, 0));
	rep(i, d)rep(j, h * w / d)
	{
		int from = i + d * j;
		int to = i + d * (j + 1);
		if(to > h * w)continue;
		int from_x = mp[from].first, from_y = mp[from].second;
		int to_x = mp[to].first, to_y = mp[to].second;

		cost[i][j+1] = cost[i][j] + abs(from_x-to_x)+abs(from_y-to_y);
	}
	int q; cin >> q;
	vector<ll> ans;
	rep(i, q)
	{
		int l, r; cin >> l >> r;
		int s = l % d;
		int n = l / d,m = r / d;
		ans.push_back(cost[s][m]-cost[s][n]);
	}
	rep(i, q)cout << ans[i] << endl;
	return;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(15);
	solve();
	return 0;
}
