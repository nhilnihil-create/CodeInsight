#include<bits/stdc++.h>
#define fo(i,a,b) for(int i= a ; i < b ; ++i)
#define rep(i,n) fo(i,0,n)
#define pln(n) printf("%lld\n",n)
#define sll(n) scanf("%lld",&n)
#define ss(n) scanf("%s",n)
#define vi vector < int >
#define pii pair < int , int >
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define dbg(x) { cout<< #x << ": " << (x) << endl; }
#define dbg2(x,y) { cout<< #x << ": " << (x) << " , " << #y << ": " << (y) << endl; }
#define dbg3(x,y,z) { cout<< #x << ": " << (x) << " , " << #y << ": " << (y) <<" , "<< #z <<": "<<(z)<<endl; }
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define vll vector<long long>
#define vvi vector<vector<int>>
#define si set<int>
#define tr(c, it) \
for(decltype(c.begin()) it = c.begin(); it!= c.end(); it++)
#define pis pair<int,string>
#define present(c, x) (c.find(x) != c.end())
#define cpresent(c, x) (find(all(c),x) != c.end())
using namespace std;
int main(){
	int n, m;
	cin >> n >> m;
	vector<int> g[n+1];
	vector<int> indegree(n+1, 0);
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		indegree[v]++;
	}    
	int dp[n+1];
	memset(dp, 0, sizeof(dp));
	// dp[i] is the longest directed path ending at vertex i
	vector<int> sources;
	for(int i = 1; i <= n; i++){
		if(indegree[i] == 0){
			sources.push_back(i);
		}
	}
	while(sources.size() > 0){
		vector<int> new_sources;
		for(int i = 0; i < sources.size(); i++){
			for(int ch: g[sources[i]]){
				dp[ch] = max(dp[ch], dp[sources[i]] + 1);
				indegree[ch]--;
				if(indegree[ch] == 0){
					new_sources.push_back(ch);
				}
			}
		}
		sources = new_sources;
	}
	
	int ans = 0;
	for(int i = 1; i <= n; i++){
		ans = max(ans, dp[i]);
	}
	cout << ans;
}