#include <bits/stdc++.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <algorithm>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define print(s) cout << s << endl
#define acc(v) accumulate(v.begin(), v.end(), 0)

using namespace std;
typedef long long ll;
const int INF = 1e9;
const ll LINF = 1e18;
const ll MOD = 1e9 + 7;
typedef pair<int, int> pii;
typedef vector<int> vint;
typedef vector<string> vstr;
typedef vector<char> vchar;

int vx[4] = {1, -1, 0, 0};
int vy[4] = {0, 0, 1, -1};
char m[1010][1010];
int main()
{
	int h, w;
	queue<pii> q;
	cin >> h >> w;
	rep(i,h){
		rep(k,w){
			char c;
			cin >> c;
			if(c=='#'){
				q.push(make_pair(k + 1, i + 1));
			}
			m[i + 1][k + 1] = c;
		}
	}
	int ans = 0;
	while (true)
	{
		queue<pii> nq;
		while(!q.empty()){
			nq.push(q.front());
			q.pop();
		}
		while(!nq.empty()){
			pii pos = nq.front();
			nq.pop();
			rep(i,4){
				int x = pos.first + vx[i];
				int y = pos.second + vy[i];
				if (m[y][x] == '.')
				{
					m[y][x] = '#';
					q.push(make_pair(x, y));
				}
			}
		}
		if(q.empty()){
			break;
		}
		ans++;
	}
	cout << ans << endl;
	return 0;
}
