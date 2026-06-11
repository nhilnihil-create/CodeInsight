#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp> 
#include <ext/pb_ds/assoc_container.hpp> 
using namespace std; 
using namespace __gnu_pbds;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
 
template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
#define FOR(i,a,b) for(int i = a; i < b; i++)
#define F0R(i,a) for(int i = 0; i < a; i++)
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) int((x).size())
#define newl '\n'
 
#define FAST ios::sync_with_stdio(0); cin.tie(0);
#define finish(x) return cout << x << "\n", 0;
#define bug(x) cerr << ">>> " << #x << " = " << x << "\n";
#define _ << " " << 
 
const ll MOD = 998244353;
const ll INF = 1e9 + 7;

const int MX = 1e5 + 5;
int N;
ll ans, A[MX], DP[MX][2];

//check int vs ll and precision
//check logic
int main(){ FAST

	cin >> N;
	FOR(i,1,N+1) cin >> A[i];

	//DP[i-1][0] = max from [1,i] if not used at i - 1
	DP[1][0] = A[1] + A[2]; DP[1][1] = -A[1]-A[2];
	FOR(i,2,N){
		//DP[i][0], DP[i][1] = max from [1,i+1]
		DP[i][0] = max({DP[i-1][0]+A[i+1],DP[i-1][1]+A[i+1]});
		DP[i][1] = max({DP[i-1][0]-2*A[i]-A[i+1],DP[i-1][1]+2*A[i]-A[i+1]});
	}
	//FOR(i,0,N) F0R(j,2) bug(i _ j _ DP[i][j]);
	ans = max({ans,DP[N-1][0],DP[N-1][1]});
	finish(ans);

	


    return 0;
}
