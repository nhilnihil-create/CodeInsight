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
const int INF = 1e18L;
const int MAX = 1e+5 + 5;
const int nax = 3e+3 + 5;

int n;
int a[MAX];
int dp[nax][nax];
int pref[MAX];

int solRec(int l, int r){
	if(dp[l][r]!=-1){
		return dp[l][r];
	}
	if(l==r){
		return dp[l][r] = 0;
	}
	int tempres = INF;
	for(int i=l;i<=r-1;i++){
		tempres =  min(tempres, solRec(l,i) + solRec(i+1,r) + pref[r]-pref[l]+a[l]);
	}
	return dp[l][r] = tempres;
}

void solve(){
	REP(i,n){
		cin >> a[i];
		if(i==0){
			pref[i] = a[i];
		}
		else{
			pref[i] = pref[i-1]+a[i];
		}
	}
	memset(dp, -1, sizeof(dp));
	
	cout << solRec(0,n-1) << endl;
	return;
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	solve();
	return 0;
}
