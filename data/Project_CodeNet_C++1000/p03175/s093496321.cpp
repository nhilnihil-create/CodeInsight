# include "bits/stdc++.h"

using namespace std;

#define endl "\n"
typedef long long int ll;

inline void fastio(){ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);}
inline void setPrecision(int n){cout.precision(n);}

//DEBUG
#define dbg(x) cerr<<(#x)<<": "<<x<<endl
#define dbgV(x) cerr<<(#x)<<": "; for(auto it: x) cerr<<it<<" "; cerr<<endl;
#define dbgS(x) cerr<<(#x)<<": "; for(auto it: x) cerr<<it<<" "; cerr<<endl;
#define dbgM(x) cerr<<(#x)<<": "; for(auto it: x) cerr<<"["<<it.f<<", "<<it.s<<"] "; cerr<<endl;
#define dbg2D(x) cerr<<(#x)<<": \n"; for(auto y: x) { for(auto it: y) cerr<<it<<" "; cerr<<endl; } cerr<<endl;
#define dbgA(x, n) cerr<<(#x)<<": "; for(int i=0;i<n;++i) cerr<<x[i]<<" "; cerr<<endl;
#define dbgVP(x) cerr<<(#x)<<": "; for(auto it: x) cerr<<"["<<it.f<<", "<<it.s<<"] "; cerr<<endl;

ll INF = 1e10;
int MOD = 1e9+7;

const int mxn = 1e5 + 5;
int n;
vector<int> adj[mxn];
ll white[mxn], black[mxn];
bool vis[mxn];

void DFS(int u){
	vis[u] = true;
	white[u] = black[u] = 1;
	if(u != 1 && adj[u].size() == 1) return;
	for(auto v: adj[u]){
		if(!vis[v]){
			DFS(v);
			white[u] *= (white[v]+black[v]);
			black[u] *= white[v];
			white[u]%=MOD;
			black[u]%=MOD;
		}
	}
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("debug.txt", "w", stderr);
    #endif
    fastio();
    cin>>n;
    for(int i=0;i<n-1;++i){
    	int x,y;
    	cin>>x>>y;
    	adj[x].push_back(y);
    	adj[y].push_back(x);
    }
    if(n == 1){
    	cout<<2;
    	return 0;
    }
    DFS(1);
    cout<<(white[1]+black[1])%MOD;
    return 0;
}
