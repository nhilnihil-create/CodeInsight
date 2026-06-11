#include <bits/stdc++.h>
using namespace std;
#define mp       make_pair
#define pb       push_back
#define all(x)   (x).begin(),(x).end()
#define YES() printf("YES\n")
#define NO() printf("NO\n")
#define Yes() printf("Yes\n")
#define No() printf("No\n")
#define in(x,y,h,w) x >= 0 && x < h && y >= 0 && y < w

#define int long long
//typedef    long long          ll;
typedef    vector<bool>       vb;
typedef    vector<int>        vi;
typedef    vector<vb>         vvb;
typedef    vector<vi>         vvi;
typedef    pair<int,int>      P;

template <typename T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template <typename T> T &chmax(T &a, const T &b) { return a = max(a, b); }
 
const int INF=1e+18;
const double EPS=1e-9;
const int MOD=1000000007;

const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};

template<class T>
struct Edge{
	int from,to;
	T cost;
	Edge(int to,T cost) : to(to),cost(cost){}
	Edge(int from,int to,T cost) : from(from),to(to),cost(cost){}
};

template<class T>
using WeightedGraph = vector<vector<Edge<T>>>;
using Graph = vector<vector<int>>;
template<class T>
using Matrix = vector<vector<T>>;

vector<int> topologicalSort(const Graph &G){
	int n = G.size();
	vector<int> inDegree(n),ret;
	queue<int> que;
	for(int i = 0;i < n;i++){
		for(int to : G[i]) inDegree[to]++;
	}
	for(int i = 0;i < n;i++){
		if(!inDegree[i]) que.push(i);
	}
	while(!que.empty()){
		int v = que.front(); que.pop();
		ret.push_back(v);
		for(int to : G[v]){
			inDegree[to]--;
			if(!inDegree[to]) que.push(to);
		}
	}
	return ret;
}

signed main(){
	int n,m;
	cin >> n >> m;
	Graph G(n),rev(n);
	for(int i = 0;i < n - 1 + m;i++){
		int a,b;
		cin >> a >> b; a--;b--;
		G[a].push_back(b);
		rev[b].push_back(a);
	}
	auto topo = topologicalSort(G);
	int topoInd[100010];
	for(int i = 0;i < n;i++) topoInd[topo[i]] = i;
	for(int i = 0;i < n;i++){
		int ma = -1;
		for(int to : rev[i]) chmax(ma,topoInd[to]);
		if(ma == -1) cout << 0 << endl;
		else cout << topo[ma] + 1 << endl;
	}
}