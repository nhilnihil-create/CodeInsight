#include <bits/stdc++.h>
#define mp       make_pair
#define pb       push_back
#define all(x)   (x).begin(),(x).end()
#define YES() printf("YES\n")
#define NO() printf("NO\n")
#define Yes() printf("Yes\n")
#define No() printf("No\n")
#define in(x,y,h,w) x >= 0 && x < h && y >= 0 && y < w
using namespace std;

//#define int long long
//typedef    long long          ll;
typedef    vector<bool>       vb;
typedef    vector<int>        vi;
typedef    vector<vb>         vvb;
typedef    vector<vi>         vvi;
typedef    pair<int,int>      P;
 
const int INF=1e+9;
const double EPS=1e-9;
const int MOD=1000000007;
 
const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};

int dp[1 << 26],tmp = 0;

signed main(){
	string s;
	cin >> s;
	for(int i = 0;i < (1 << 26);i++) dp[i] = INF;
	dp[0] = 0;
	for(int i = 0;i < s.length();i++){
		tmp ^= 1 << (s[i] - 'a');
		for(int j = 0;j < 26;j++){
			dp[tmp] = min(dp[tmp],dp[tmp ^ (1 << j)] + 1);
		}
	}
	if(dp[tmp]) cout << dp[tmp] << endl;
	else cout << 1 << endl;
	return 0;
}