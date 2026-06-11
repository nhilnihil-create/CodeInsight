#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <algorithm>
#include <climits>

using namespace std;
 
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define t_times int t; cin >> t; while(t--)
#define fr(i, st, n) for(int i = (int )st; i < (int )n; i++)
#define rfr(i, en, st) for(int i = (int )en; i >= (int )st; i--)
#define all(c) (c).begin(), (c).end()
#define fi first
#define se second
#define pb push_back
#define sz(a) (int)(a).size()
 
typedef long long int LL;
typedef pair< int, int> ii;
typedef vector< int> vi;
typedef vector< ii> vii;
typedef vector< vi> vvi;
 
const int mod = 1e9 + 7;
const LL INF = 9e18 + 2e17;
const int inf = 2e9;
const double eps = 1e-10;
 // START FROM HERE

int main(int argc, char const *argv[])
{
	fastio;

	int n, k; cin >> n >> k;
	vi h(n); fr(i,0,n) cin >> h[i];

	vi dp(n,INT_MAX);
	dp[0] = 0;
	fr(i,1,n) {
		fr(j,max(i-k,0),i) {
			dp[i] = min(dp[i], dp[j] + abs(h[j]-h[i]));
		}
	}
	cout<<dp[n-1]<<endl;




	return 0;
}