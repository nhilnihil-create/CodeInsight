//Never stop trying
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef long long ll;
#define int ll
typedef double db;
typedef long double ld;

typedef pair<int,int> pi;
#define fi first
#define se second

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<str> vs;
typedef vector<pi> vpi;

#define pb push_back
#define eb emplace_back
#define pf push_front

#define lb lower_bound
#define ub upper_bound

#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define endl "\n"

const int MOD = 1e9+7; //998244353
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0}; //right left down up

void IO(){
#ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
#endif 
}

const int MX=1e5+10;

int N;
int t[30][30];
int memo[(1)<<(21)];

int solve(int m){
	int i=0;
	for(int j=0; j<N; j++) if((m)&((1)<<(j))) i++;
	if(i==N) return 1;

	if(memo[m]!=-1) return memo[m];

	int ans=0;
	for(int j=0; j<N; j++) if(t[i][j]==1 && ((m)&((1)<<(j)))==0) ans+=solve((m)|((1)<<(j))),ans%=MOD;
	return memo[m]=ans;
}


int32_t main(){
   boost;
   IO();

   memset(memo,-1,sizeof(memo));
   cin>>N;
   for(int i=0; i<N; i++) for(int j=0; j<N; j++) cin>>t[i][j];

   cout << solve(0) << endl;

   

   return 0;
}

