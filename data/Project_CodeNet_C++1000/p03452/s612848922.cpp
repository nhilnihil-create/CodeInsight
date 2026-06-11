#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
#define ep emplace_back
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(v) v.begin(), v.end()
#define revall(v) v.rbegin(), v.rend()
constexpr int mod=1000000007;
constexpr int mod1=998244353;
vector<int> dx={0,1,0,-1},dy={-1,0,1,0};
bool inside(int y,int x,int h,int w){ if(y<h && y>=0 && x<w && x>=0) return true; return false; }
template<class T> inline bool chmin(T& a, T b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b){ if(a < b){ a = b; return true; } return false; }






int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n,m;cin >> n >> m;
	if(m == 0){
		cout << "Yes" << endl;
		return 0;
	}
	vector<int> l(m), r(m), d(m);
	vector<vector<pii>> g(n);
	rep(i,m){
		cin >> l.at(i) >> r.at(i) >> d.at(i);
		l.at(i)--;
		r.at(i)--;
		g[l.at(i)].pb(mp(r.at(i),d.at(i)));
		g[r.at(i)].pb(mp(l.at(i),-d.at(i)));
	}
	vector<int> x(n);
	queue<int> q;
	vector<bool> visited(n);
	bool ok = true;
	rep(j,n){
		if(visited.at(j)) continue;
		visited.at(j) = true;
		q.push(j);
		while(!q.empty()){
			int cur = q.front();q.pop();
			rep(i,g[cur].size()){
				int next = g[cur][i].first, t = g[cur][i].second;
				if(visited.at(next)){
					if(x[next] - x[cur] != t) ok = false;
				}
				else{
					visited.at(next) = true;
					x.at(next) = x.at(cur) + t;
					q.push(next);
				}
			}
		}
	}
	if(ok) cout << "Yes" << endl;
	else cout << "No" << endl;
}
