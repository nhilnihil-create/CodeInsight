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
#define mod (int)(1e9 + 7) 
using namespace std;
vector<int> g[(int)1e5 + 5];


int mul(int a, int b){
	return ((ll)a%mod * b%mod)%mod;
}
pair<int,int> dfs(int i, int parent){
	
	int black = 0; // at least one is black
	int white = 1; // all white
	for(int ch: g[i]){
		if(ch != parent){
			pair<int,int> p = dfs(ch, i);
			int meme = white;
			white = mul(white, p.second);
			black = (mul(meme, p.first)%mod + mul(black, (p.first + p.second)))%mod;
		}
	}
	return {white, (black%mod + white%mod)%mod};
	
}

int main(){
	int N;
	cin >> N;
	for(int i = 1; i <= N-1; i++){
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	pair<int,int> ans = dfs(1, -1);
	cout << (ans.first%mod + ans.second%mod)%mod << endl;
}
