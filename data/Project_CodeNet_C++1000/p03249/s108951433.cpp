// comment
// 가장 큰게 리프였다는 사실을 알았으면 해볼만 했을지도..
// 가장 작은 값을 기준으로 트리를 만들면 밑으로 갈수록 점점 증가한다라는 사실을 인지하는 능력?

#include <bits/stdc++.h>

using namespace std;

#define SZ(v) ((int)(v).size())
#define ALL(v) (v).begin(),(v).end()
#define one first
#define two second
using ll = long long;
using pi = pair<int, int>;
using pli = pair<ll, int>;
const int INF = 0x3f3f3f3f;
const ll LINF = 1ll * INF * INF;

const int MAX_N = 1e5 + 100;

int N, Ix[MAX_N];
ll Ds[MAX_N];
int S[MAX_N];

int findD(ll d) {
	int ix = lower_bound(Ds+1, Ds+N+1, d) - Ds;
	if(Ds[ix] == d) return ix;
	return -1;
}

int Vis[MAX_N];
vector<int> Ed[MAX_N];

int main() {
	cin >> N;
	vector<pli> temp;
	for(int i=1; i<=N; i++) {
		scanf("%lld", &Ds[i]);
		temp.emplace_back(Ds[i], i);
	}
	sort(Ds+1, Ds+N+1);
	sort(ALL(temp));
	for(int i=0; i<N; i++) Ix[i+1] = temp[i].two;
	for(int i=1; i<=N; i++) S[i] = 1;
	
	vector<pi> Ans;
	//for(int i=1; i<=N; i++) printf("%lld ", Ds[i]); puts("");
	for(int i=N; i>=2; i--) {
		ll pd = Ds[i] + 2*S[i] - N;
		int ix = findD(pd);
		//printf("%lld [%lld + 2*%d - %d] %d\n", pd, Ds[i], S[i], N, ix);
		if(ix == -1 || ix == i) return puts("-1") < 0;
		S[ix] += S[i];
		Ans.emplace_back(Ix[ix], Ix[i]);
		Ed[Ix[ix]].push_back(Ix[i]);
		Ed[Ix[i]].push_back(Ix[ix]);
	}

	ll real = 0;
	queue<int> Q;
	int root = Ix[1];
	Vis[root] = 1; Q.push(root);
	while(!Q.empty()) {
		int v = Q.front(); Q.pop();
		for(int w: Ed[v]) if(Vis[w] == 0) {
			Vis[w] = Vis[v] + 1;
			Q.push(w);
		}
	}
	int all = 0;
	for(int i=1; i<=N; i++) if(Vis[i] != 0) {
		all++;
		real += Vis[i] - 1;
	}
	if(all != N || real != Ds[1]) return puts("-1") < 0;


	for(auto p: Ans) {
		int x, y; tie(x, y) = p;
		printf("%d %d\n", x, y);
	}
	return 0;
}
