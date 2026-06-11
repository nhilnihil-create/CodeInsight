#include <bits/stdc++.h> 
using namespace std;
 
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define pb					push_back
#define eb					emplace_back
#define mp					make_pair
#define endl 				'\n'
#define gc					getchar_unlocked
#define pc					putchar_unlocked
#define FASTIO std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
#define MAX_DIGITS 7 // 7 digits in 1 000 000
static const long long buf_len = (1 << 14);
static const long long buf_max = (1 << 04);
static char buf_out[buf_len];
static char buf_num[buf_max];
static long long buf_pos = 0;
#ifdef _WIN32
#define GETCHAR() _getchar_nolock()
#define PUTCHAR(c) _putchar_nolock(c)
#elif __unix__
#define GETCHAR() getchar_unlocked()
#define PUTCHAR(c) putchar_unlocked(c)
#else
#define GETCHAR() getchar()
#define PUTCHAR(c) putchar(c)
#endif
#define MOD 1000000007  
#define lld long long 
typedef long long ll;
static const lld nax=1e6+5;
 
const ll INF2=-1e18;
const int MAXN = 16;
const int MAXL = (1 << 16) + 10;
 
vector<int> grafo[MAXL];
ll valor[MAXL],dp[MAXL],mat[MAXN][MAXN];
int vis[MAXL],N;
 
void brute(int pos,int bitmask,int submask){
 
	if(pos == N){
		if(__builtin_popcount(submask) == 0) return;
		grafo[bitmask].push_back(submask);
		return;
	}
 
	brute(pos+1,bitmask,submask);
	brute(pos+1, bitmask | (1 << pos), submask );
	brute(pos+1, bitmask | (1 << pos), submask | (1 << pos) );
 
}
 
void calcula(){
 
	for(int bitmask = 1;bitmask < (1 << N);bitmask++){
		for(int i = 0;i<N;i++){
			if(!(bitmask & (1 << i))) continue;
			for(int j = i+1;j<N;j++){
				if(!(bitmask & (1 << j))) continue;
				valor[bitmask] += mat[i][j];
			}
		}
	}
 
}
 
ll solve(int bitmask){
 
	if(bitmask == 0) return 0;
	if(vis[bitmask]) return dp[bitmask];
 
	vis[bitmask] = 1;
 
	ll best = INF2;
 
	for(int submask : grafo[bitmask]){
		best = max(best, solve(bitmask ^ submask) + valor[submask] );
	}
 
	return dp[bitmask] = best;
 
}
 
int main() {
    FASTIO
    
    cin >> N;
	for(int i = 0;i<N;i++){
		for(int j = 0;j<N;j++){
			cin >> mat[i][j];
		}
	}
 
	brute(0,0,0);
	calcula();
 
    cout<<solve((1 << N) - 1);
    return 0;
}