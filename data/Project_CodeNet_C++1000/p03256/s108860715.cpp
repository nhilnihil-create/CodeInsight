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

vector<int> G[200010];

signed main(){
	int n,m,x[200010],y[200010],acnt[200010] = {},bcnt[200010] = {};
	string s;
	bool ng[200010] = {};
	cin >> n >> m >> s;
	for(int i = 0;i < m;i++){
		cin >> x[i] >> y[i]; x[i]--;y[i]--;
		G[x[i]].pb(y[i]);
		G[y[i]].pb(x[i]);
	}
	queue<int> que;
	for(int i = 0;i < n;i++){
		for(int v : G[i]){
			if(s[v] == 'A') acnt[i]++;
			else bcnt[i]++;
		}
		if(!acnt[i] || !bcnt[i]){
			que.push(i);
			ng[i] = true;
		}
	}
	while(que.size()){
		int v = que.front();que.pop();
		ng[v] = true;
		for(int to : G[v]){
			if(!ng[to]){
				if(s[v] == 'A') acnt[to]--;
				else bcnt[to]--;
				if(!acnt[to] || !bcnt[to]){
					que.push(to);
					ng[to] = true;
				}
			}
		}
	}
	for(int i = 0;i < n;i++){
		if(!ng[i]){
			Yes();
			return 0;
		}
	}
	No();
	return 0;
}