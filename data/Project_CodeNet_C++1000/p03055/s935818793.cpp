#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <queue>
#include <set>
#include <math.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<ll, P> Q;
const ll mod = 1000000007;
const ll INF = 1000000000000000;
ll bit[100010], num;
ll par[100010], sz[100010];
ll n, a, b, ans, dp[100010], leaf[100010], res[2];
vector<ll> road[200010];
bool flg[200010];

struct edge { ll to, cost; };
ll V;
vector<edge> G[300010];
ll d[300010];

ll root(int x) { // �f�[�^x��������؂̍����ċA�œ���Froot(x) = {x�̖؂̍�}
	if (par[x] == x) return x;
	return par[x] = root(par[x]);
}

void unite(int x, int y) { // x��y�̖؂𕹍�
	int rx = root(x); //x�̍���rx
	int ry = root(y); //y�̍���ry
	if (rx == ry) return; //x��y�̍�������(=�����؂ɂ���)���͂��̂܂�
	par[rx] = ry; //x��y�̍��������łȂ�(=�����؂ɂȂ�)���Fx�̍�rx��y�̍�ry�ɂ���
}

bool same(int x, int y) { // 2�̃f�[�^x, y��������؂������Ȃ�true��Ԃ�
	int rx = root(x);
	int ry = root(y);
	return rx == ry;
}

ll sum(ll i)
{
	ll s = 0;
	while (i > 0)
	{
		s += bit[i];
		i -= i & -i;
	}
	return s;
}

void add(ll i, ll x)
{
	while (i <= num)
	{
		bit[i] += x;
		i += i & -i;
	}
}

ll po(ll x, ll y)
{
	if (y == 0) return 1;
	if (y % 2)
	{
		return po(x, y - 1) * x % mod;
	}
	else
	{
		ll yyy = po(x, y / 2);
		return yyy * yyy % mod;
	}
}

ll pow_mod(ll x, ll y)
{
	ll res = 1;
	while (y > 0)
	{
		if (y % 2 == 1)
		{
			(res *= x) %= mod;
		}
		(x *= x) %= mod;
		y /= 2;
	}
	return res;
}

ll div(ll x)
{
	return po(x, mod - 2);
}


ll dfs(ll x)
{
	flg[x] = true;

	vector<ll> vec;
	vec.push_back(0);
	for (int i = 0; i < road[x].size(); i++)
	{
		if (flg[road[x][i]]) continue;
		vec.push_back(dfs(road[x][i]));
	}

	sort(vec.begin(), vec.end());
	reverse(vec.begin(), vec.end());

	if (vec.size() != 1)
	{
		ans = max(ans, vec[0] + vec[1] + 1);
	}
	
	return vec[0] + 1;
}

int main(void)
{
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		cin >> a >> b;
		road[a].push_back(b);
		road[b].push_back(a);
	}

	if (n == 1)
	{
		cout << "First" << endl;
		return 0;
	}
	if (n == 2)
	{
		cout << "Second" << endl;
		return 0;
	}

	dfs(1);

	if (ans % 3 == 2)
	{
		cout << "Second" << endl;
	}
	else
	{
		cout << "First" << endl;
	}
	
	int www;
	cin >> www;
}
