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

void solve(string s, string t){
	int n=s.length(), m = t.length();
	int dp[n+1][m+1];
	REP(i, n+1){
		REP(j, m+1){
			if(i==0 || j==0){
				dp[i][j] = 0;
			}
			else{
				if(s[i-1] == t[j-1]){
					dp[i][j] = dp[i-1][j-1] + 1;
				}
				else{
					dp[i][j] = max({dp[i][j-1], dp[i-1][j], dp[i-1][j-1]});
				}
			}
		}
	}
	string res;
	int i=n, j=m;
	while(i>0 && j>0){
		if(s[i-1] == t[j-1]){
			res.pb(s[i-1]);
			i--;
			j--;
		}
		else{
			if(dp[i-1][j] > dp[i][j-1]){
				i--;
			}
			else{
				j--;
			}
		}
	}
	reverse(res.begin(), res.end());
	cout << res << endl;
	return;
}

int32_t main(){
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		string s, t;
		cin >> s >> t;
		solve(s, t);
		return 0;
}