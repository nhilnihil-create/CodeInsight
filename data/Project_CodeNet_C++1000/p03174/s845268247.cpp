#include <iostream>
#include <vector>
#include <limits>
#include <cstdlib>
#include <algorithm>
#include <functional>
#include <complex>
#include <iomanip>
#include <cassert>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <bitset>
#include <cstring>
#include <climits>
using namespace std;
#define nl '\n'
#define sp ' '
#define f first
#define s second
#define boost() cin.tie(0); cout.tie(0); cin.sync_with_stdio(0)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int MAXN = 21; // REMEMBER TO CHANGE
const int MOD = 1e9+7;
int N, dp[1<<MAXN];
bool mat[MAXN][MAXN];
int main(){
	boost();
	cin >> N;
	for(int i = 0;i<N;i++){
		for(int j = 0;j<N;j++){
			cin >> mat[i][j];
		}
	}
	dp[0] = 1;
	for(int mask = 0;mask<(1<<N);mask++){
		int paired = __builtin_popcount(mask);
		for(int i = 0;i<N;i++){
			if(mat[paired][i]&&!(mask&(1<<i))){
				int newmask = mask|(1<<i);
				dp[newmask] = (dp[newmask]+dp[mask])%MOD;
			}
		}
	}
	cout << dp[(1<<N)-1] << nl;
	return 0;
}