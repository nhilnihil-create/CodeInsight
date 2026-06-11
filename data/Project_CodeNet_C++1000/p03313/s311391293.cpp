#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define eb emplace_back
#define mt make_tuple
#define all(x) (x).begin(), (x).end() 
#define MOD 1000000007

typedef long long ll;
typedef pair <int, int> ii;
typedef pair <ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef long double ld;

const ll INF=LLONG_MAX;
const int BT=18;
int dp[1<<BT][2]; 

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	int n; 
	scanf("%d",&n);
	for(int i=0; i<(1<<n); i++)scanf("%d",&dp[i][1]);
	for(int i=0; i<n; i++){
		for(int mask=0; mask < (1<<n); mask++){
			if(!dp[mask][1])continue;
			if(mask>>i&1){
				dp[mask][0]=max(dp[mask][0],dp[mask^(1<<i)][1]);
				if(dp[mask][0]>dp[mask][1])swap(dp[mask][0],dp[mask][1]);
			}
		}
	}
	int res = 0;
	for(int i=1; i<(1<<n); i++){
		res = max(res,dp[i][0]+dp[i][1]);
		cout << res << endl;
	}
}
	
// READ & UNDERSTAND
// ll, int overflow, array bounds, memset(0)
// special cases (n=1?), n+1 (1-index)
// do smth instead of nothing & stay organized
// WRITE STUFF DOWN
