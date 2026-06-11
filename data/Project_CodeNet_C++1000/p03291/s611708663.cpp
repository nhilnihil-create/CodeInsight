#include <bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define ff first
#define ss second
#define P 1000000007
#define in(x, a, b) (a <= x && x < b)

using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
const ll inf = 1000000001, INF = (ll)1e18 + 1;

string s;
int dp[100010][4];

void solve() {
	cin >> s;
	
	dp[0][0] = 1;
	for(int j = 1; j < 4; j++) dp[0][j] = 0;
	
	for(int i = 1; i <= s.length(); i++) {
		for(int j = 0; j < 4; j++) dp[i][j] += dp[i - 1][j];
		for(int j = 0; j < 4; j++) dp[i][j] %= P;
		if(s[i - 1] == 'A') {
			dp[i][1] += dp[i - 1][0];
		} else if(s[i - 1] == 'B') {
			dp[i][2] += dp[i - 1][1];
		} else if(s[i - 1] == 'C') {
			dp[i][3] += dp[i - 1][2];
		} else {
			for(int j = 1; j < 4; j++) dp[i][j] += dp[i - 1][j - 1];
			for(int j = 0; j < 4; j++) dp[i][j] %= P;
			dp[i][0] += (dp[i - 1][0] * 2) % P;
			dp[i][1] += (dp[i - 1][1] * 2) % P;
			dp[i][2] += (dp[i - 1][2] * 2) % P;
			dp[i][3] += (dp[i - 1][3] * 2) % P;
		}
		
		for(int j = 0; j < 4; j++) dp[i][j] %= P;
	}	
	
	cout << dp[s.length()][3] << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	solve();
    return 0;
}