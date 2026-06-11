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
const int MAX = 1e+5;
int n;
int a[MAX];

void solve(){
	int dp[n+2];
	REP(i, n){
		dp[i] = INT_MAX;
	}
	dp[0] = 0;
	REP(i, n){
		FORN(j, i+1, i+3){
			dp[j] = min(dp[j], dp[i]+abs(a[i]-a[j]));
		}
	}
	cout << dp[n-1] << endl;
	return;
}

int32_t main(){
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cin >> n;
		REP(i, n){
			cin >> a[i];
		}
		solve();
		return 0;
}

