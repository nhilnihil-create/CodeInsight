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

using namespace std;
typedef pair<int, int> pii;
typedef long long int ll;
typedef pair<ll, ll> pll;
int dx[4] = { 1,0,0,-1 };
int dy[4] = { 0,1,-1,0 };
#define MOD 1000000007
#define ARRAY_MAX 100005

const int INF = 1e9 + 7;


ll n, m;
vector<int> G[ARRAY_MAX];
int color[ARRAY_MAX];//各頂点の色(1:黒、2;白,0:まだ塗られていない)
bool ans = true;//二部グラフかどうか


void dfs(int now) {


	for (auto to : G[now])
	{
		if (color[now] == color[to])
		{
			//二部グラフではない
			//ループができている
			ans = false;
			return;
		}
		if (color[to] == 0)
		{
			//まだ塗られていない
			color[to] = 3 - color[now];//color[now]==1なら2が、color[now]==2なら1が入る(隣同士で違う色が塗られる)
			dfs(to);
		}


	}
}



int main() {


	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	color[0] = 1;//1は黒を表す
	dfs(0);
	
	if (ans)
	{
		//二部グラフなら完全二部グラフにできる
		//二部に分けた両者の間で全頂点間に辺を張ることができる

		int black = 0, white = 0;
		for (int i = 0; i < n; i++)
		{
			if (color[i] == 1)
			{
				black++;
			}
			else
			{
				white++;
			}
		}
		ll ans = 1LL * black * white - m;
		cout << ans << endl;
	}
	else
	{
		//二部グラフではないなら完全グラフにできる
		//奇数長の閉路がある場合は任意の2地点を奇数距離で移動できるので結ぶことができる
		ll ans = 1LL * n * (n - 1) / 2 - m;
		cout << ans << endl;
	}

	return 0;
}