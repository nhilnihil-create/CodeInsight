#include<bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define RFOR(i,b,a) for(int i = (b) - 1; i >= (a); i--)
#define ITER(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(a,value) memset(a, value, sizeof(a))

#define SZ(a) (int)a.size()
#define ALL(a) a.begin(),a.end()
#define PB push_back
#define MP make_pair

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PII;

const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000 + 7;
const LL LINF = INF * (LL)INF;

const int MAX = 2 * 1000 * 100 + 47;
int C[MAX][2];
string s;
vector<int> g[MAX];
queue<int> q;

int main()
{
	//freopen("in.txt","r", stdin);
	ios::sync_with_stdio(false);cin.tie(0);
	int n, m;
	cin >> n >> m >> s;
	FOR(i, 0, m)
	{
		int a,b;
		cin >> a >> b;
		a--;
		b--;
		g[a].PB(b);
		C[a][s[b] - 'A']++;
		g[b].PB(a);
		C[b][s[a] - 'A']++;
	}

	int cnt = 0;
	FOR(i, 0, n)
	{
		if (C[i][0] == 0 || C[i][1] == 0)
		{
			q.push(i);
		}
	}

	while (!q.empty())
	{
		int v = q.front();
		q.pop();
		cnt++;

		FOR(i, 0, SZ(g[v]))
		{
			int to = g[v][i];
			if (C[to][0] == 0 || C[to][1] == 0) continue;

			C[to][s[v] - 'A']--;
			if (C[to][s[v] - 'A'] == 0)
			{
				q.push(to);
			}
		}
	}

	if (cnt == n)
	{
		cout << "No" << endl;
		return 0;
	}

	cout << "Yes" << endl;
}
