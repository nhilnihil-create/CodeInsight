
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
#include <iomanip>
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
const int MAX = 1e+5 + 5;

int n, k;

void solve(){
	int a[n];
	REP(i, n){
		cin >> a[i];
	}
	
	int dp[k+1];
	memset(dp, 0, sizeof(dp));
	dp[0] = 0;
	FORN(i, 1, k+1){
		REP(j, n){
			if(i-a[j]>=0 && dp[i-a[j]]==0){
				dp[i] = 1;
			}
		}
	}
	cout << (dp[k] ? "First" : "Second") << endl;
	return;
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	solve();
	return 0;
}
