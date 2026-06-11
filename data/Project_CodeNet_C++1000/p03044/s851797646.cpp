// ░░░░░░░░( •̪●)░░░░░░░░░░░░░░░░░░░░░░░░
// ░░░░░░███████ ]▄▄▄▄▄▄▄▄▃░░░▃░░░░ ▃░
// ▂▄▅█████████▅▄▃▂░░░░░░░░░░░░░░░░░
// [███████████████████].░░░░░░░░░░░░░░
// ◥⊙▲⊙▲⊙▲⊙▲⊙▲⊙▲⊙◤...░░░░░░░░░░░░

//PointBlank's code (⌐■_■)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
 
#define repp(I, A, B) for(int I = A; I <= B; I++)
#define rep(I, A, B) for(int I = A; I < B; I++)
#define rrep(I, B, A) for(int I = B; I >= A; I--)
#define pb emplace_back
#define ff first
#define ss second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define LB lower_bound
#define UB upper_bound
#define MP make_pair
#define mem(A, B) memset(A, B, sizeof(A));
#define mem0(A) memset(A, 0, sizeof(A));
#define quickio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug(this) cerr<<"> "<<#this<<" : "<<this<<"\n"
#define bitsf(n) __builtin_popcount(n)
#define in_edges(M) repp(I, 1, M){ll A, B, C; cin >> A >> B >> C; v[A].pb(B, C&1), v[B].pb(A, C&1);}
#define in_edges2(M) repp(I, 1, M){ll A, B; cin >> A >> B; v[A].pb(B);}
#define endl "\n"
ll power(ll x, ll y); 

const ll MOD = 1000000007;
const int MX = 1e5 + 5;

vector<pair<int, int> > v[MX];
int col[MX], vis[MX];

void dfs(int s, int sum){
	vis[s] = 1;
	col[s] = sum & 1; 
	for(auto i : v[s]) if(!vis[i.ff]){
		dfs(i.ff, sum + i.ss);
	}
}
 
int main() //PointBlank's code ¯\_(ツ)_/¯
{
	int n;
	cin >> n;
	in_edges(n - 1);
	dfs(1, 0);
	repp(i, 1, n) cout << col[i] << endl;
}

ll power(ll x, ll y)
{ 
    ll res = 1; x %= MOD;
    while(y > 0){if(y & 1) res = (res*x) % MOD; y = y>>1, x = (x*x) % MOD;} 
    return res; 
}