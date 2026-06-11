#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<n;i++)
#define P pair<int,int>
#define int long long
#define mod (int)(1e9+7)
#define inf (int)(3e18)
#define all(v) v.begin(),v.end()
#define prique(T) priority_queue<T,vector<T>,greater<T>>
using namespace std;

template<class T> inline void chmax(T &a, T b) {
	a = std::max(a, b);
}
template<class T> inline void chmin(T &a, T b) {
	a = std::min(a, b);
}

int mod_pow(int x, int y, int m = mod) {
	int res = 1;
	while (y) {
		if (y % 2) {
			res *= x;
			res %= m;
		}
		x = x * x % mod;
		y /= 2;
	}
	return res;
}

int n,m;
string s;
vector<int>G[200005];
vector<int>same[200005];
bool used[200005],used2[200005];
void dfs(int x){
	used[x]=true;
	used2[x]=true;
	for(int i:G[x]){
		if(s[i]!=s[x])continue;
		for(int j:G[i]){
			if(s[i]==s[j])continue;
			if(used2[j]){
				cout<<"Yes"<<endl;exit(0);
			}
			if(!used[j]){
				dfs(j);
			}
		}
	}
	used2[x]=false;
}
signed main() {
	cin>>n>>m>>s;
	rep(i,m){
		int a,b;cin>>a>>b;a--;b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	rep(i,n){
		if(!used[i]){
			dfs(i);
		}
	}
	cout<<"No"<<endl;
}
