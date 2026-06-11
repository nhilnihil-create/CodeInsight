#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<math.h>
#include<deque>
using namespace std;
typedef long long ll;
#define int long long
typedef vector<int> VI;
typedef pair<int, int> pii;
typedef priority_queue<int> PQ;
#define fore(i,a) for(auto &i:a)
#define REP(i,n) for(int i=0;i<n;i++)
#define eREP(i,n) for(int i=0;i<=n;i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define eFOR(i,a,b) for(int i=(a);i<=(b);++i)
#define SORT(c) sort((c).begin(),(c).end())
#define rSORT(c) sort((c).rbegin(),(c).rend())
#define LB(x,a) lower_bound((x).begin(),(x).end(),(a))
#define UB(x,a) upper_bound((x).begin(),(x).end(),(a))
#define INF 1000000000
#define LLINF 9223372036854775807
#define mod 1000000007
//vector<vector<int> > dp;
//vector<vector<vector<int> > > vvvi;
//dp=vector<vector<int> >(N, vector<int>(M,0));
//vector<pair<int,int> > v;
//v.push_back(make_pair(x,y));
//priority_queue<int,vector<int>, greater<int> > q2;


int N, M;
vector<VI> G;
int color[100010];

bool dfs(int u, int c) {
	color[u] = c;
	REP(i, G[u].size()) {
		int v = G[u][i];
		if (color[v] == c)return false;
		if (color[v] == 0 && !dfs(v, -c)) {
			return false;
		}
	}
	return true;
}




signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	G.resize(N);
	REP(i, M) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	int B = 0, W = 0;
	if (dfs(0, 1)) {
		REP(i, N) {
			if (color[i] == 1) {
				B++;
			}
			else if(color[i]==-1){
				W++;
			}
		}
		cout << B * W - M << endl;
	}
	else {
		cout << ((N*(N - 1)) / 2) - M << endl;
	}
	
	return 0;
}

