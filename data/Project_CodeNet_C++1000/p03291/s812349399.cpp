#include <bits/stdc++.h>
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = ((int)(n)-1); i >= 0; i--)
#define all(x) (x).begin(),(x).end()
 
using namespace std;
using ll = long long;
 
struct edge { int to, cost; };
 
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> P;
 
const int INF = ~(1<<31);
const int MOD = 1e9+7;
const double EPS = 1e-10;
const double PI = acos(-1.0);
 
const int mx4[] = {0,1,0,-1};
const int my4[] = {1,0,-1,0};
const int mx8[] = {0,1,1,1,0,-1,-1,-1};
const int my8[] = {1,1,0,-1,-1,-1,0,1};

ll dp[100010][4];

int main(){
	string s;
	cin >> s;

	dp[0][0] = 1;
	for(int i = 0; i < s.size(); i++){
		for(int j = 0; j < 4; j++){
			dp[i+1][j] += dp[i][j] * (s[i] == '?' ? 3 : 1);
			dp[i+1][j] %= MOD;
		}
		for(int j = 0; j < 3; j++){
			if(s[i] == '?' || s[i] == 'A'+j){
				dp[i+1][j+1] += dp[i][j];
				dp[i+1][j+1] %= MOD;
			}
		}
	}

	cout << dp[s.size()][3];

	return 0;
}