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
int H, W;

void solve(){
	char a[H][W];
	REP(i, H){
		REP(j, W){
			cin >> a[i][j];
		}
	}
	int dp[H+1][W+1];
	memset(dp, 0,  sizeof(dp));
	FORN(i, 1, H+1){
		FORN(j, 1, W+1){
			if(i==1 && j==1){
				dp[i][j] = 1;
			}
			else{
				if(a[i-1][j-1] == '#'){
					dp[i][j] = 0;
				}
				else{
					dp[i][j] = (dp[i-1][j] + dp[i][j-1])%MODO;
				}
			}
		}
	}
	cout << dp[H][W] << endl;
	return;
}

int32_t main(){
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cin >> H >> W;
		solve();
		return 0;
}

