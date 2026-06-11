#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <string>
#include <stack>
#include <cmath>
#include <cstring>
#include <climits>
using namespace std;

#define FORN(i, j, k) for(int i=j;i<k;i++)
#define FORR(i, j, k) for(int i=j;i>=k;i--)
#define REP(i, n) FORN(i, 0, n)
#define int long long
#define pii pair<int, int>
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl '\n'

const int MODO = 1e+9 + 7;
int n;

void solve(){
	int dp[n][3];
	memset(dp, 0, sizeof(dp));
	int h[3];
	cin >> h[0] >> h[1] >> h[2];
	dp[0][0] = h[0];
	dp[0][1] = h[1];
	dp[0][2] = h[2];
	FORN(i, 1, n){
		cin >> h[0] >> h[1] >> h[2];
		REP(m, 3){
			REP(k, 3){
				if(k!=m){
					dp[i][m] = max(dp[i][m], dp[i-1][k]+h[m]);
				}
			}
		}
	}
	cout << max({dp[n-1][0], dp[n-1][1], dp[n-1][2]}) << endl;
	return;
}

int32_t main(){
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cin >> n;	
		solve();
		return 0;
}

