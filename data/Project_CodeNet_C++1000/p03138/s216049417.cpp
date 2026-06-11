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
 
const int INF = 1e9;
const int MOD = 1e9+7;
const double EPS = 1.0e-10;
const double PI = acos(-1.0);
 
const int mx4[] = {0,1,0,-1};
const int my4[] = {1,0,-1,0};
const int mx8[] = {0,1,1,1,0,-1,-1,-1};
const int my8[] = {1,1,0,-1,-1,-1,0,1};

ll dp[100][2];

int main(){
	ll n,k;
	cin >> n >> k;
	vector<ll> a(n);
	rep(i,n) cin >> a[i];
	memset(dp,-1,sizeof(dp));
	dp[60][0] = 0;
	for(int i = 59; i >= 0; i--){
		ll mask = 1ll<<i,cnt = 0;
		for(int j = 0; j < n; j++) if(a[j]&mask) cnt++;
		if(dp[i+1][1] != -1){
			dp[i][1] = max(dp[i][1],dp[i+1][1]+mask*max(cnt,n-cnt));
		}
		if(dp[i+1][0] != -1){
			if(k&mask){
				dp[i][0] = max(dp[i][0],dp[i+1][0]+mask*(n-cnt));
				dp[i][1] = max(dp[i][1],dp[i+1][0]+mask*cnt);
			}else{
				dp[i][0] = max(dp[i][0],dp[i+1][0]+mask*cnt);
			}
		}
	}
	cout << max(dp[0][0],dp[0][1]) << endl;
	return 0;
}